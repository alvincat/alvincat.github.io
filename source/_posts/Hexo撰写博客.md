---
title: "Hexo撰写博客"
date: 2017-08-10 19:53:17
description: "博客摘要：本文讲解怎么使用Markdown语法书写能够适用Hexo系统的博客文章的方法。"
categories: ["Hexo"]
tags: ["Hexo", "Hexo撰写博客"]
layout: true
comments: false
top: 10
copyright: true
---

## Markdown文件头部格式
　　要使一篇博客能够与博客系统的`标签`和 `分类`关联。必须在每篇博客对应的Markdown文件头部书写必要信息。格式如下：
```
---
title: ""		#文章标题
date:                   #文件创建时间,Hexo默认按照文件创建时间排序
description:            #文章摘要
categories: [""]        #文章类别
tags: ["", ""]          #文章标签
layout: true            #是否使用样式      
comments: false         #是否添加文章评论
top: 10			#置顶级别,数值越大，优先级越高
copyright: true         #是否添加版权信息
---
```
　　**注意**：属性冒号后必须要有一个空格，多个标签要使用方括号包围，以逗号分隔。例如本文的MarkDown文件头实例如下：
```
---
title: "Hexo撰写博客"
date: 2017-08-10 19:53:17
description: "博客摘要：本文讲解怎么使用Markdown语法书写能够适用Hexo系统的博客文章的方法。"
categories: ["Hexo"]
tags: ["Hexo", "Hexo撰写博客"]
layout: true
comments: false
top: 10
copyright: true
---
```

## 书写博客摘要的方法
### `方法1`
在Markdown源文件的头部信息中添加`description` 属性，然后将摘要内容用双引号(英文)包含即可。
### `方法2`

　　除了使用方法1，也可以使用一下方法进行操作。首先，在MarkDown头部信息之后书写博客的摘要。然后在其后添加如下内容即可。注意以下内容的前后都要有个空行。

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