---
title: "Hexo Quick Start"
categories: ["Hexo"]
tags: ["hexo install", "hexo options"]
date: 2017-08-10 17:16:26
layout: true
comments: true
top: 
copyright: true
---

摘要：本文内容摘自Hexo中文官网，主要内容为Hexo安装以及配置方法。若要转载，请尊重版权，注明来源。

<!-- more -->

## 什么是Hexo
[Hexo](https://hexo.io/zh-cn/)是一个简单快速高效的博客框架。Hexo使用 Markdown（或其他渲染引擎）解析文章，即可利用靓丽的主题生成静态网页。

## 安装
### 安装前提
安装 Hexo 相当简单。然而在安装前，您必须检查电脑中是否已安装下列应用程序：
+ Git
+ Node.js

### 安装Git
+ Windows：下载并安装 [Git](https://git-scm.com/download/win)
+ Mac：使用 Homebrew, MacPorts ：brew install git;或下载 安装程序 安装。
+ Linux (Ubuntu, Debian)：sudo apt-get install git-core
+ Linux (Fedora, Red Hat, CentOS)：sudo yum install git-core

### 安装Node.js
  安装 Node.js 的最佳方式是使用[nvm](https://github.com/creationix/nvm)

cURL:
```
$ curl https://raw.github.com/creationix/nvm/master/install.sh | sh
```

Wget:
```
$ wget -qO- https://raw.github.com/creationix/nvm/master/install.sh | sh
```

安装完成后，重启终端并执行下列命令即可安装 Node.js。

```
$ nvm install stable
```
或者您也可以下载 [安装程序](http://nodejs.org/) 来安装。

> **Windows 用户**
> 对于windows用户来说，建议使用安装程序进行安装。安装时，请勾选Add to 
> PATH选项。另外，您也可以使用Git Bash，这是git for windows自带的一组程序，提供了Linux风格的shell，在该环境下，您可以直接用上面提到的命令来安装Node.js。打开它的方法很简单，在任意位置单击右键，选择“Git  Bash Here”即可。由于Hexo的很多操作都涉及到命令行，您可以考虑始终使用Git Bash来进行操作。

### 安装 Hexo

　　所有必备的应用程序安装完成后，即可使用 npm 安装 Hexo。
```
$ npm install -g hexo-cli
```

## 建站

　　安装 Hexo 完成后，请执行下列命令，Hexo 将会在指定文件夹中新建所需要的文件。
```
$ hexo init <folder> 
$ cd <folder>
$ npm install
```

**说明**：为Hexo在本地的目录，windows可根据对应情况书写。第二条命令的目的是将新建的目录`<folder>`作为当前目录。第三部执行Hexo初始化操作，创建必要的文件。

新建完成后，指定文件夹的目录如下：
```
.
├── _config.yml
├── package.json
├── scaffolds
├── source
|   ├── _drafts
|   └── _posts
└── themes
```

### _config.yml

　　网站的 [配置](https://hexo.io/zh-cn/docs/configuration.html) 信息文件，您可以在此配置大部分的参数。

### package.json

　　应用程序的信息。EJS, Stylus和 Markdown renderer已默认安装，您可以自由移除。
```
package.json
{
  "name": "hexo-site",
  "version": "0.0.0",
  "private": true,
  "hexo": {
    "version": ""
  },
 
 "dependencies": {
    "hexo": "^3.0.0",
    "hexo-generator-archive": "^0.1.0",
    "hexo-generator-category": "^0.1.0",
    "hexo-generator-index": "^0.1.0",
    "hexo-generator-tag": "^0.1.0",
    "hexo-renderer-ejs": "^0.1.0",
    "hexo-renderer-stylus": "^0.2.0",
    "hexo-renderer-marked": "^0.2.4",
    "hexo-server": "^0.1.2"
  }
}
```

### scaffolds
[模版](https://hexo.io/zh-cn/docs/writing.html) 文件夹。当您新建文章时，Hexo 会根据 scaffold 来建立文件。
Hexo的模板是指在新建的Markdown文件中默认填充的内容。例如，如果您修改scaffold/post.md中的Front-matter内容，那么每次新建一篇文章时都会包含这个修改。

### source

资源文件夹是存放用户资源的地方。除 `_posts` 文件夹之外，开头命名为 `_` (下划线)的文件 / 文件夹和隐藏的文件将会被忽略。Markdown 和 HTML 文件会被解析并放到 `public` 文件夹，而其他文件会被拷贝过去。

### themes

[主题](https://hexo.io/zh-cn/docs/themes.html) 文件夹。Hexo 会根据主题来生成静态页面。若想使用非默认主题，可以下载对应的主题，然后将对应的文件夹放在该目录下。

## 配置

您可以在 `_config.yml` 中修改大部份的配置。

### 网站

| 参数            | 描述                                       |
| ------------- | ---------------------------------------- |
| `title`       | 网站标题                                     |
| `subtitle`    | 网站副标题                                    |
| `description` | 网站描述                                     |
| `author`      | 您的名字                                     |
| `language`    | 网站使用的语言                                  |
| `timezone`    | 网站时区。Hexo 默认使用您电脑的时区。[时区列表](https://en.wikipedia.org/wiki/List_of_tz_database_time_zones)。比如说：`America/New_York`, `Japan`, 和 `UTC` 。 |

其中，`description`主要用于SEO，告诉搜索引擎一个关于您站点的简单描述，通常建议在其中包含您网站的关键词。`author`参数用于主题显示文章的作者。

### 网址

| 参数                   | 描述                                       | 默认值                         |
| -------------------- | ---------------------------------------- | --------------------------- |
| `url`                | 网址                                       |                             |
| `root`               | 网站根目录                                    |                             |
| `permalink`          | 文章的 [永久链接](https://hexo.io/zh-cn/docs/permalinks.html) 格式 | `:year/:month/:day/:title/` |
| `permalink_defaults` | 永久链接中各部分的默认值                             |                             |

> 网站存放在子目录
>
> 如果您的网站存放在子目录中，例如 `http://yoursite.com/blog`，则请将您的 `url` 设为 `http://yoursite.com/blog` 并把 `root` 设为 `/blog/`。

其他设置请参考[配置设置](https://hexo.io/zh-cn/docs/configuration.html)

## 生成文件

使用 Hexo 生成静态文件快速而且简单。
```
$ hexo generate
```

### 监视文件变动

Hexo 能够监视文件变动并立即重新生成静态文件，在生成时会比对文件的 SHA1 checksum，只有变动的文件才会写入。
```
$ hexo generate --watch
```

### 完成后部署

您可执行下列的其中一个命令，让 Hexo 在生成完毕后自动部署网站，两个命令的作用是相同的。
```
$ hexo generate --deploy
$ hexo deploy --generate
```

简写: 上面两个命令可以简写为
```
hexo g U+2212.d
hexo d  -g
```
## 搭建本地Hexo服务器

### Hexo-server

Hexo 3.0 把服务器独立成了个别模块，您必须先安装 [hexo-server](https://github.com/hexojs/hexo-server) 才能使用。

```
$ npm install hexo-server --save
```

安装完成后，输入以下命令以启动服务器，您的网站会在 `http://localhost:4000` 下启动。在服务器启动期间，Hexo 会监视文件变动并自动更新，您无须重启服务器。

```
$ hexo server
```

如果您想要更改端口，或是在执行时遇到了 `EADDRINUSE` 错误，可以在执行时使用 `-p` 选项指定其他端口，如下：
```
$ hexo server -p 5000
```

### 静态模式

在静态模式下，服务器只处理 `public` 文件夹内的文件，而不会处理文件变动，在执行时，您应该先自行执行 `hexo generate`，此模式通常用于生产环境（production mode）下。
```
$ hexo server -s
```

### 自定义 IP

服务器默认运行在 `0.0.0.0`，您可以覆盖默认的 IP 设置，如下：
```
$ hexo server -i 192.168.1.1
```

　　指定这个参数后，您就只能通过该IP才能访问站点。例如，对于一台使用无线网络的笔记本电脑，除了指向本机的`127.0.0.1`外，通常还有一个`192.168.*.*`的局域网IP，如果像上面那样使用`-i`参数，就不能用`127.0.0.1`来访问站点了。对于有公网IP的主机，如果您指定一个局域网IP作为`-i`参数的值，那么就无法通过公网来访问站点。

## 部署

　　Hexo 提供了快速方便的一键部署功能，让您只需一条命令就能将网站部署到服务器上。
```
$ hexo deploy
```

　　在开始之前，您必须先在 `_config.yml` 中修改参数，一个正确的部署配置中至少要有 `type` 参数，例如：
```
deploy:
  type: git
```

　　您可同时使用多个 deployer，Hexo 会依照顺序执行每个 deployer。
```
deploy:
- type: git
  repo:
- type: heroku
  repo:
```

> 缩进
>
> YAML依靠缩进来确定元素间的从属关系。因此，请确保每个deployer的缩进长度相同，并且使用空格缩进。

### 使用Git同步

　　安装 [hexo-deployer-git](https://github.com/hexojs/hexo-deployer-git)。
```
$ npm install hexo-deployer-git --save
```

修改配置。
```
deploy:
  type: git
  repo: <repository url>
  branch: [branch]
  message: [message]
```

| 参数        | 描述                                       |
| --------- | ---------------------------------------- |
| `repo`    | 库(Repository)地址                          |
| `branch`  | 分支名称。如果您使用的是 GitHub 或 GitCafe 的话，程序会尝试自动检测。 |
| `message` | 自定义提交信息                                  |

```
message自定义提交信息默认为  Site updated: {{ now('YYYY-MM-DD HH:mm:ss') }})
```

## 常用命令

### init
```
$ hexo init [folder]
```

　　新建一个网站。如果没有设置 `folder` ，Hexo 默认在目前的文件夹建立网站。

### generate
```
$ hexo generate
```

生成静态文件。

| 选项               | 描述          |
| ---------------- | ----------- |
| `-d`, `--deploy` | 文件生成后立即部署网站 |
| `-w`, `--watch`  | 监视文件变动      |

该命令可以简写为
```
$ hexo g
```

### server
```
$ hexo server
```

　　启动服务器。默认情况下，访问网址为： `http://localhost:4000/`。

| 选项               | 描述              |
| ---------------- | --------------- |
| `-p`, `--port`   | 重设端口            |
| `-s`, `--static` | 只使用静态文件         |
| `-l`, `--log`    | 启动日记记录，使用覆盖记录格式 |

该命令可以简写为：
```
$ hexo s
```

### deploy
```
$ hexo deploy
```

部署网站。

| 参数                 | 描述           |
| ------------------ | ------------ |
| `-g`, `--generate` | 部署之前预先生成静态文件 |

该命令可以简写为：
```
$ hexo d
```

### clean
```
$ hexo clean
```

　　清除缓存文件 (`db.json`) 和已生成的静态文件 (`public`)。在某些情况（尤其是更换主题后），如果发现您对站点的更改无论如何也不生效，您可能需要运行该命令。

### version
```
$ hexo version
```

显示 Hexo 版本。

**温馨提示**：

1. 当安装完node.js后，就可以使用npm命令。npm其实是同node.js一起安装的一个包管理工具。
2. 当使用hexo命令时，必须当期目录切换至Hexo工程环境的根目录，即使用`hexo init` 命令创建的目录。
3. hexo-server开启服务时，支持对Markdown文件修改后实时刷新网页，更新结果。因此，不需要重启服务，即可展示修改后的效果。


