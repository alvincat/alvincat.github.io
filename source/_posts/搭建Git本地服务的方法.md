---
title: "搭建Git本地服务的方法"
date: 2018-05-24 21:16:22
description: "博客摘要：本文简要的介绍了在本地搭建Git服务的方法，以及克隆本地Git仓库的方法。"
categories: ["Git"]
tags: ["Git", "搭建Git本地服务"]
layout: true
top: 
---

## 安装Git及其相关设置

### 安装Git
要想服务器提供Git托管代码服务或者使用Git托管代码，必须先安装Git软件。以下是主流系统安装Git的方法。
#### Debian系列(Debian,Ubuntu)
Debian系列系统使用`apt-get`安装：
```shell
apt-get install git
```
#### Redhat系列(Redhat, Fodara, CentOS)
Redhat系列系统使用`yum`即可安装，命令如下：
```shell
yum install git-core
```
#### Linux系统自定义安装
一般使用系统自带的安装工具安装的Git多半不是最新版本。若要体验最新版的Git。需要自己下载最新的安装包并手动安装。手动安装的方法如下：
1. 下载最新的Git软件包，假设为git-1.7.2.2.tar.gz。
2. 然后编译并安装：
```shell
tar -zxvf git-1.7.2.2.tar.gz
cd git-1.7.2.2
./configure prefix
make
sudo make install
```
#### Windows安装Git
windows系统安装Git操作相对容易。在[git官网](https://git-scm.com/)下载与系统对应的版本(32位或64位)exe程序，安装即可。

### 创建管理Git仓库的git用户及其安全设置
若要再Linux系统上提供Git代码托管服务，还需要一些额外的设置。设置内容如下：
1. 创建git用户，专门用于管理Git管理的代码和登录
```shell
su			#切换为root权限
adduser git  #添加用户git
passwd git   #设置git用户登录密码
```

2. 配置passwd文件，禁止git用户使用shell登录。使用`vi`打开`/ect/passwd`文件找到类似于`git:x:1001:1001:,,,:/home/git:/bin/bash`的行，修改为`git:x:1001:1001:,,,:/home/git:/bin/bash-shell`。这样git用户可以正常通过ssh的方式使用git，但是无法使用shell登录。

## 客户端生成RSA公钥
客户端安装完Git后，需要生成RSA公钥，然后保存到服务端的公钥管理文件中。
Git客户端机机器在安装完Git后，需要设置Git的配置文件。该设置相当于设置当前机器的唯一标识，用于Git服务器统一管理使用Git服务的用户。设置方法为输入如下命令(windows系统在Git bash中输入)：
```shell
git config --global user.name "your-name"
git config --global user.email "your_email@xxx.com"
```
注意：git config命令中的`--global`参数，表示这台机器上的所有Git仓库都会使用这个配置。如果要在某个特定的项目中使用其他名字或者电邮，只要去掉 `--global` 选项重新配置即可，新的设定保存在当前项目的 `.git/config` 文件里。

### Linux生成RSA公钥的方法
1. 检查ssh key是否存在
   一般ssh key一般会放在当前用户目录下的`.ssh`目录下，名字为id_rsa.pub。若该目录下存在id_isa.pub文件，就不需要再创建了。否则，就需要手动创建。
2. 生成ssh key
   在命令行下输入以下命令：
   ```shell
   ssh-keygen -t rsa -C "your_email@xxx.com"
   ```
默认情况下，会在当前用户目录下生成id_ras和id_rsa.pub两个文件。

### Windows生成RSA公钥的方法
1. 在Git Bash中输入如下命令：` ssh-keygen -t rsa -C "your-email-address"`
2. 然后会在目录`c:\user\yourname\.ssh` 目录下生成两个文件id_rsa和id_rsa.pub文件。

## 在服务端添加客户端RSA公钥
1.打开服务端Git的RSA认证

```shell
   vi /ect/ssh/sshd_config #打开sshd配置文件
   #取消一下几项的注释
   #RSAAuthentication yes
   #PubkeyAuthentication yes
   #AuthorizedKeysFile .ssh/authorized_keys
   service sshd restart  #重启sshd服务
```
   
2.将Git客户端生成SSH key复制到服务端机器上。

```shell
   Linux系统
   scp -r id_rsa.pub example.git@192.168.20.1:/home/git/

   Windows用户
   pscp c:\user\yourname\.ssh\id_rsa.pub git@192.168.20.1:/home/git/
```
   
3.然后将对应的SSH key添加到Git服务端的公钥管理文件中。Git服务端的公钥管理文件存放位置一般在`/home/git/.ssh`目录下，文件名为`authorized_keys` 。若服务端没有与之对应的目录和文件，可以手动创建对应的目录和文件。通过如下命令导入客户端的ssh key。

   ```shell
   cat id_rsa.pub >> /home/git/.ssh/authorized_keys
   ```
   
## 在服务端部署git仓库
### 直接在服务端部署
在服务端执行以下命令即可：
```shell
cd /home/git
mkdir example.git
cd example.git
git --bare init
```
此时，就会在`/home/git`目录下生成一个`example.git`的代码托管文件夹。
### 在本体部署上传至服务端
1.将现有仓库导出为裸仓库。假设当前仓库名为`example`。执行如下命令:
```shell
git clone --bare example example.git
```
2.然后将该仓库上传至服务器即可。假设服务器IP地址为：192.168.20.1

```shell
scp -r example.git example.git@192.168.20.1:/home/git/
```

## 在客户端克隆git仓库
首先进入将要保存Git文件的文件夹，执行如下命令：

```shell
git clone git@192.168.56.2:/home/git/sample.git
```

其中克隆Git仓库的地址可以是ssh协议地址：`user_name@ip_address:file_path`，可以是https协议地址：`https://github.com/user_name/project_name`，也可以是git://协议地址：`git://github.com/schacon/grit.git` 。
