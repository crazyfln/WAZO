# WAZO

搭建NTP服务器步骤：
1. 在服务器上依次安装ntp-4.2.8-win32-setup.exe（NTP服务器软件）以及ntp-time-server-monitor-104.exe（NTP服务器监控软件）
2. 安装时选择默认安装即可
3. 定位到NTP服务器安装目录，找到\etc\ntp.conf文件，去掉下面两行的注释（即删除前面的#号），保存文件
    server 127.127.1.0
    fudge 127.127.1.0 stratum 12
4. 创建\etc\ntp.drift文件，然后编辑文件，在文件中添加内容“0.000”（不要引号），然后保存关闭
5. 在NTP监控客户端里重启NTP服务器即可，Start Type设为Automatically即可，每次重启系统会自动启动NTP服务
6. 所有相机的NTP都设置为服务器，端口用默认的123即可

PlayVideo工程：

此工程为视频检索客户端软件，使用VS2015生成可执行文件后运行即可。打开后填入视频服务器或录像机的IP地址，端口，用户名，密码后登录，然后选择视频通道号，起始时间，结束时间后点击播放即可。
播放结束后自动停止，也可在播放过程中手动停止。播放过程中点击抓图按钮即可自动抓图并保存在当前文件夹。点击注销按钮可从视频服务器或录像机注销登录。

PlayVideoActiveX工程：

此工程为视频检索ActiveX控件，用于在IE浏览器中检索视频。使用VS2015生成ocx控件后，在命令行中使用regsvr32进行注册。注册成功后，使用regedit注册表编辑器，在HKEY_CLASSES_ROOT下找到PlayVideoActiveX控件，并记下它的CLSID。
编辑index.html示例文件，将CLSID填入对应的Object标签。通过js代码调用Login()函数并填入IP地址，端口，用户名，密码，即可登录视频服务器/录像机；调用Play函数并填入视频通道号，起始时间，结束时间，即可播放视频；调用Stop函数停止播放视频；调用Logout函数注销登录。
