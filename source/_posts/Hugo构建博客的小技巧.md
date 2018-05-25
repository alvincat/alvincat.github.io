---
title: "Hugo构建博客的小技巧"
date: 2018-05-24 22:47:00
description: "博客摘要：本文的提供的主要内容是官方文档中没有而且又有一定实用性的内容。使用的主题是hyde-y。"
categories: ["Hugo"]
tags: ["Github Page", "Hugo", "构建博客"]
layout: true
top: 
---

## 侧边栏的修改
本节主要说明与侧边栏修改有关的操作。
### 修改侧边栏的相对位置
首先，官方文档提供的侧边栏标签创建过程如下：
1. 在博客根目录下的`data`文件夹下新建`Menu.toml`文本文件。
2. 然后将官方提供的文本复制到该文本中即可。
  官方提供的实例如下：

```
[about]
    Name = "About"
    URL = "/about"
[posts]
    Name = "Posts"
    Title = "Show list of posts"
    URL = "/post"
[tags]
    Name = "Tags"
    Title = "Show list of tags"
    URL = "/tags"
```

而这种格式得到的页面往往不是我们想要的，要想改变这种情况，按以下方法处理即可。
```
[1]
    Name = "Blogs Posts"
    Title = "Show list of posts"
    URL = "/post" 
[2]
    Name = "Blog Tags"
    Title = "Show list of tags"
    URL = "/tags"
[3]
    Name = "About Me"
    URL = "/about"
```

说明：按以上方式修改侧边栏标签，系统会根据标签的序号排序，序号越小，越靠前。因此，可以通过修改这些标签的顺序和编号来改变网页中的标签的排列顺序。

### 修改侧边栏的标题
修改侧边栏的标签很容易。修改方法是：直接修改`Menu.toml`各个标签中的`Name`属性即可。

### 添加侧边栏标签
针对hyde-y模板，可以添加`topic` ，`keyword`标签。此处以`topic`标签为例。
首先在根目录的`config.toml`文件中添加以下内容。
```
[taxonomies]
    topic = "categories"
```

然后再`Menu.toml`添加对应的标签项(首先确定其名称和排列次序)。例如：
```
[2]
    Name = "Blog categories"
    Title = "Show list of categories"
    URL = "/categories" 
```



## 初始化md文件的头部信息

使用Hugo构建文件时，一定要使用Hugo新建md文件，该文件一定要**包含创建文件的时间信息**。这个时间信息可以保证你在其他系统中构建网站是生成的网页能够和之前的顺序保持一致。

首先，在`themes/hyde-y/archetypes`目录下有一个`default.md`文件。该文件为`hyde-y`的默认初始化md文件头部信息的模板。
其次，在博客根目录下的`archetypes`目录下，也有一个`default.md`文件。这是hugo新建md文件的默认模板。因此，可以将该文件更名，然后将`hyde-y/archetypes`目录下的文件复制到此处，然后进行修改。我修改后的文件如下：
```
---
title: "{{ replace .Name "-" " " | title }}"
date: {{ .Date }}
draft: false
author: "alvincat"
description: "博客摘要："
categories: [""]
tags: ["", ""]
---
```

说明：

1. `title`部分的格式在使用命令`hugo new file_name.md`时，直接将文件名(不包含后缀)导入到`title`字段。
2. `data` 部分会自动生成创建文件的时间。
3. `draft`部分若为`true`时，会将文件保存为草稿文件，因此默认为`false` 。
4. `author` 为发布博客的作者，会显示在博客标题下方。
5. `description` 为博客的摘要部分，是博客的简单说明，强烈建议填写。
6. `categories` 为博客的主题，该部分内容会呈现在网站的`topic`列表中。
7. `tags`为博客的标签，该内容会出现在博客标题的下方而且还会出现在网站的`tags`列表中。

## 修改浏览器标签的logo

修改方法：用自己设计的logo图像(保存为favicon.png)替换替换主题`hyde`中的文件`static/favicon.png`即可。

[hugo安装部署博客方法](http://www.gohugo.org/)

[hyde的安装和配置方法](http://www.gohugo.org/theme/hyde-y/)

[hugo主题](http://www.gohugo.org/theme/)





