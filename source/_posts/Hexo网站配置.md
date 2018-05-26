---
title: "Hexo网站配置"
date: 2018-05-24 17:25:30
description: "博客摘要：本文主要介绍Hexo博客中一些主要内容的配置方法。"
categories: ["Hexo"]
tags: ["Hexo page set", "Hexo"]
layout: true
comments: true
top: 
---

在 Hexo 中有两份主要的配置文件，其名称都是 \_config.yml。 其中，一份位于站点根目录下，主要包含 Hexo 本身的配置；另一份位于`主题目录`下，这份配置由主题作者提供，主要用于配置主题相关的选项。

为了描述方便，在以下说明中，将前者称为 `站点配置文件`， 后者称为` 主题配置文件`。 
## 更换主题
### 安装NexT
　　Hexo 安装主题的方式非常简单，只需要将主题文件拷贝至站点目录的 themes 目录下， 然后修改配置文件即可。具体到 NexT 来说，安装步骤如下。

### 下载主题
　　如果你熟悉 Git， 建议你使用 克隆最新版本 的方式，之后的更新可以通过 git pull 来快速更新， 而不用再次下载压缩包替换。 

**克隆最新版**
在终端窗口下，定位到 Hexo 站点目录下。使用 `Git` checkout 代码：

```
$ cd your-hexo-site
$ git clone https://github.com/iissnan/hexo-theme-next themes/next
```

### 启用主题

​      与所有 Hexo 主题启用的模式一样。当 克隆/下载 完成后，打开 站点配置文件，找到 `theme` 字段，并将其值更改为 `next`。    
```
theme: next
```

​      到此，NexT 主题安装完成。下一步我们将验证主题是否正确启用。在切换主题之后、验证之前，我们最好使用 `hexo clean` 来清除 Hexo 的缓存。

### 验证主题
​      首先启动 Hexo 本地站点，并开启调试模式（即加上 `--debug`），整个命令是 `hexo s --debug`。      在服务启动的过程，注意观察命令行输出是否有任何异常信息，如果你碰到问题，这些信息将帮助他人更好的定位错误。      当命令行输出中提示出：    
```
INFO  Hexo is running at http://0.0.0.0:4000/. Press Ctrl+C to stop.
```

此时即可使用浏览器访问 `http://localhost:4000`，检查站点是否正确运行。    

## 主题设置
其它设置请参照NexT文档进行设置。例如设置主题，语言，菜单，头像，昵称等内容。[Next设置文档](http://theme-next.iissnan.com/getting-started.html)

若要使主页边栏中 `分类` `标签` `关于` 页面能够加载，需要进行以下设置。

### 创建文件夹(分类 标签 关于)
```
$ cd your-hexo-site
$ hexo new page categories
$ hexo new page tags
$ hexo new page about
```
上述操作其实是在hexo根目录中，./source目录下新建`categories`，`tags`， `about`文件夹。并在各个文件夹下新建一个index.md文件。

### 设置页面类型
各个index.md的内容形如：
```
---
title: 标签
date: 2017-08-01 10:20:57
type: "tags"
comments: false #禁用评论
---
```
其中type类型与index.md所在的文件夹的文件名一致。例如tags文件夹中的index.md的type属性为"tags"。
### 修改菜单
在菜单中添加链接。编辑`主题配置`文件 ， 添加对应属性到 menu 中，如下:
```
menu: 
  home: /
  archives: /archives
  categories: /categories
  about: /about
  tags: /tags
```

至此，基本内容已经可以使用了。

参考文档：
官方参考：[NexT使用文档](http://theme-next.iissnan.com/getting-started.html)
网上资源：[hexo的next主题个性化教程：打造炫酷网站](http://blog.csdn.net/qq_33699981/article/details/72716951)
师弟的文档：[github Pages + Hexo搭建个人博客（二） 提升篇](http://wangxinri.cn)