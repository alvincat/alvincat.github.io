---
title: "Hexo撰写博客"
date: 2018-05-24 19:53:17
description: "博客摘要：本文讲解怎么使用Markdown语法书写能够适用Hexo系统的博客文章的方法。"
categories: ["Hexo"]
tags: ["Hexo", "Hexo撰写博客"]
layout: true
comments: true
top: 
---

## Markdown文件头部格式
　　要想使一篇博客能够与博客系统的`标签`和 `分类`关联。必须在每篇博客对应的Markdown文件头部书写必要信息。格式如下：
```
---
title: hexo撰写博客    		#博客的标题
tags: [hexo,hexo写博客]	 #博客中涉及标签，即关键词
categories: hexo		   #博客的分类
---
```
　　**注意**：属性冒号后必须要有一个空格，多个标签要使用方括号包围，以逗号分隔。

## 书写博客摘要
　　接下来就要书写博客的主要内容，即博客的摘要。以便直观的了解博客内容。
## 显示阅读全文框
　　为了能够在博客一页中显示更多内容，需要将一篇博客折叠，当读者需要阅读时，点击`阅读全文`，才会展开一篇博客内容。方法如下：

```
<!-- more -->    #在博客摘要后，另起一行，输入本行中的内容即可
```

## 发布文章

　　除以上格式需要注意外，其他格式与普通的Markdown文件并无差别。但需要注意的是:

+ Hexo中的Markdown文件中不能使用Tab，只能使用空格作为空白符
+ Hexo中在使用大花括号`{`时，要么使用网页中的转义，要么放在代码块中，否则会出错

　　若按上述格式编辑好文档，就可以发布并查看解析是否正确了。

　　发布方法：将编辑好的Markdown文件放置在Hexo根目录中的./source/\_posts目录下即可。

## 本地测试

　　编写好的文档可以现在本地测试，解析正确无误后，再发布到github上，减少不必要的麻烦。操作步骤如下：
```
$ cd hexo-root-directory
$ hexo generate(g)
$ hexo server(s)
```

　　当打开本地Hexo-server后，即可看到Markdown在网页中的解析效果。若有一些偏差，可实时修改网页对应的Markdown文件。Markdown文件修改保存后，刷新网页即可看到修改后的效果，很方便，^__^。

## 上传至github

　　当本地调试无误后，即可上传至github。使用如下命令：
```
$ cd hexo-root-directory
$ hexo g -d
```