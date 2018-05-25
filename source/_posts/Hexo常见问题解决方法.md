---
title: "Hexo常见问题解决方法"
date: 2018-05-24 19:21:30
description: "摘要：本文主要记录我自己在配置Hexo，写博客过程中遇到的问题，以及对应的解决方法。" 
categories: ["Hexo"]
tags: ["hexo problem"]
layout: true
top: 
---

## 问题1 
**错误提示**：
FATAL can not read a block mapping entry;a multiline key may not be an implicit key at line 9,column 7:
author: alvincat

**原因**：根目录下\_config.yml的配置文件中，各个属性的属性值与属性右侧的冒号之间必须要有一个空格，否则就会出现以上错误。
**解决方法**：查看\_config.yml文件，检查各个属性冒号右侧有无空格与属性值分隔。

## 问题2

**错误提示**：
FATAL (unknown path) [Line 7, Column 533]
Error: Unable to call `now`, which is undefined or falsey

**原因**：Markdown文件使用一些hexo特殊符号，导致Hexo对这些符号无法解析。这些符号主要是
```
{{}}，{% %}
```
**解决方法**：
```
将 { } 的大括号通过&#123; &#125; 进行转换  
或者将{ }及其中的内容包含在 ``` 代码中
```

## 问题3
**错误提示**：
ssh: Could not resolve hostname github.com: Name or service not known fatal: Could not read from remote repository.

**原因**：github的仓库使用ssh的连接方式，但是git未配置ssh连接密钥。

**解决方法**：

> 
方法1：修改hexo对应仓库的clone连接方式为https
> 
方法2：在本地git中创建和使用ssh，以ssh方式连接。制作方法参看[git-ssh 配置和使用](https://segmentfault.com/a/1190000002645623)
