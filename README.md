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
