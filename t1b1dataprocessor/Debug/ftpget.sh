ftp -4 -i ftp.t1b1.nl << END_SCRIPT
cd public_html
mget index.xml
quit
END_SCRIPT
