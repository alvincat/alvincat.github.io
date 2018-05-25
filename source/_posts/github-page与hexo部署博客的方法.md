---
title: "Github Page与hexo部署博客的方法"
date: 2018-05-24 19:08:19
description: "博客摘要：本文主要将hexo生成的静态网页部署到Github Page中的方法。"
categories: ["hexo"]
tags: ["hexo", "部署博客"]
layout: true
top: 
---

本文为转载博客，(https://www.cnblogs.com/ld1024/p/5913169.html)。 若使用该博客，请注明出处！

## Github仓库准备
1. 创建仓库，http://your-user-name.github.io
2. 创建两个分支：master 与 hexo
    在本地创建一个文件夹，用于保存本地文件，本例中假设为该目录为Github。
    进入Github目录，通过git bash执行如下命令：
    ```
    touch README.md
    git init
    git add README.md
    git commit -m "first commit"
    git remote add origin https://github.com/your-user-name/your-user-name.github.io.git
    git push -u origin master
    ```
    在本地新建一个分支： 
        git branch hexo
    切换到你的新分支: 
        git checkout hexo
    将新分支发布在github上： 
        git push origin hexo
    至此分支创建完毕
3. 在github网站中设置hexo为默认分支

## Hexo创建
在Github目录文件夹下通过Git bash依次执行
1. npm install hexo
2. hexo init <folder>
  如果指定 <folder>，便会在目前的资料夹建立一个名为 <folder> 的新资料夹；否则会在目前资料夹初始化。
3. npm install
4. npm install hexo-deployer-git
5. hexo generate  生成网站
6. hexo server  启动本地服务器
  网站会执行在http://localhost:port （port 预设为 4000，可在 _config.yml 设定）

## Hexo和Github关联

1. 修改_config.yml中的deploy参数，分支应为master；
2. hexo generate -deploy(可以简化为hexo g -d) 生成推送到github的master分支
  此时访问your-user-name.github.io即可查看生成的站点内容


## Hexo源码备份

1. 进入本地的Github文件夹下，执行
2. git clone https://github.com/your-user-name/your-user-name.github.io.git
    此时显示分支为hexo
3. git add --all
4. git commit -m "blog source commit"
5. git push origin hexo
  至此博客源代码就备份到了hexo分支上面。

## 后期维护以及博客更新
在本地对博客进行修改（添加新博文、修改样式等等）后，通过下面的流程进行管理。
首先进入博客主文件夹，例如hexoBolg.
依次执行git add .、git commit -m "..."、git push origin hexo指令将改动推送到GitHub（此时当前分支应为hexo）；
然后再执行hexo g -d发布网站到master分支上。
