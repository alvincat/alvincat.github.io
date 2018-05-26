---
title: "GithubPage与Hexo部署博客的方法"
date: 2017-08-10 19:08:19
description: "博客摘要：本文主要将hexo生成的静态网页部署到Github Page中的方法。"
categories: ["hexo"]
tags: ["hexo", "部署博客"]
layout: true
comments: true
top: 
---

## Github仓库准备
1. 创建仓库，http://your-github-username.github.io
2. 在第1步的仓库中创建两个分支，分别为master(默认分支)与Hexo。然后将Hexo分支设置为默认分支。

## Hexo本地安装及测试
### Hexo本地安装
1.安装node.js和Git。再次不在赘述。
2.npm 安装 Hexo命令行工具。命令如下：
```
npm install -g hexo-cli
```
3.安装完Hexo后，执行如下命令：

```bash
# 创建Hexo工作目录，并且在该目录下完成初始化工作。
$ hexo init <folder>
```
执行完以上命令后，就会在指定目录下生成如下文件结构：

```
.
├── node_modules
├── scaffolds
├── source
|   └── _posts
└── themes
|   └── landscape
├── _config.yml
├── package.json
└── package-lock.json
```

4.官方文档中说要接着执行以下命令：

```
$ cd <folder>
$ npm install
```
以上命令的目的是：更新hexo的工具包。

5.执行以下命令(在根目录下)安装Hexo本地服务器：

```
$ npm install hexo-server --save
```

6.执行以下命令(在根目录下)安装Hexo Git部署工具：

```
$ npm install hexo-deployer-git --save
```

### Hexo 本地构建博客及测试
1.执行以下命令，生成静态网页：

```bash
#或者使用`hexo g`
hexo generate
```
**说明** ：这一步执行成功后会在根目录下创建一个`public`文件夹，并在该目录下生成静态网站的所有数据。

2.执行以下命令，启动本地服务器：

```bash
#或者使用`hexo s`
hexo server
```
若以上命令没有错误，通过浏览器输入网址`localhost:port` (port 默认值为 4000，可在 \_config.yml 设定)就可以在本地浏览Hexo生成的页面了。
说明：通过以上步骤，就可以在本地测试博客的功能。若本地测试无误，就可以执行后续操作了。

## Hexo和Github Page关联
1. 修改\_config.yml中的deploy参数，修改实例如下：

```
deploy: 
  type: git
  repo: git@github.com:alvincat/alvincat.github.io.git
  branch: master
```
说明：此处使用的是ssh协议进行git通信。若您未配置ssh通信方式，请使用https协议传输(对应使用https格式的协议)。

2.然后，执行以下命令：

```shell
#或者使用`hexo deploy`
hexo d
```
说明：第2步的实际操作过程就是将博客根目录下的`public`目录中的所有文件推送到第1步指定的github仓库的指定分支中。若过程没有错误，就可以使用`https://your-user-name.github.io`访问生成的站点内容了。

## Hexo博客源代码备份
1.进入博客根目录下，执行以下命令：

```shell
git clone git@github.com:alvincat/alvincat.github.io.git
git add -A
git commit -m "Fist commit"
git push origin Hexo
```
若该过程不出错，博客源代码就会备份到hexo分支中。

## 博客内容还原
当我们不小心删除了本地博客，或者想在其他设备上修改博客时，就可以使用我们已经备份好的博客源代码进行数据还原。还原方法如下：
1.安装Git和node.js。
2.然后再本地某个文件夹下执行如下命令，其中blog_fold为博客目录。
```shell
$ git clone git@github.com:alvincat/alvincat.github.io.git blog_fold
$ cd blog_fold

#安装hexo命令行工具
$ npm install -g hexo-cli
$ npm install
```
后面的步骤就和初始构建hexo博客系统一致。唯一不同之处在于，还原的Hexo系统已经有了初始的资源，不需要初始化，即不需要执行`hexo init`命令。
