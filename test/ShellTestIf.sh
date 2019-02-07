#!/bin/sh

#这个文件在Windows 下编辑过，在Windows下每一行结尾是\n\r，而Linux下则是\n
#sed -i 's/\r$//' xxx.sh 会把xxx.sh中的行尾的\r替换为空白

#结果：
#ywf handsome
#ywf handsome to

#YWF=handsome 这种结果也一样(不带双引号一样,最好带引号用于区分变量)
YWF="handsome"
#这种写法不行，无法判断会报错 ./ShellTestIf.sh: 行 3: [handsome: 未找到命令
#if [$YWF = "handsome"];then
#改为有空格的(handsome不带双引号结果一样(最好带引号用于区分变量),$YWF带双引号("$YWF")也一样)：
if [ $YWF = "handsome" ];then
echo "ywf handsome"
elif [ $YWF = "handsome2" ]
then
echo "ywf very handsome"
elif [ "$YWF" = "handsome2" ]
then
echo "ywf very handsome 2"	
else
echo "ywf very very handsome"
fi

######################################################################
if test $YWF = "handsome"
then
echo "ywf handsome too"
elif test $YWF = "handsome" ; then
echo "ywf very handsome too"
else
echo "ywf very very handsome too"	
fi

 

 

 

 

 

 


######################################################################
if [ -f $1 ]; then
echo "SET(CMAKE_SYSTEM_NAME Linux)" > $1
echo "SET(CMAKE_C_COMPILER \"$2-gcc\")" >> $1
echo "SET(CMAKE_CXX_COMPILER \"$2-g++\")" >> $1
echo "SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)" >> $1
echo "SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)" >> $1
echo "SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)" >> $1
echo "Generate Cmake File Done!"
else
echo "The $1 is not exist!"
exit 1
fi

if [ "$1" = "" ]
then
else	
app_ver=$1	
lang=$2
echo app_ver---${app_ver} 
echo lang---${lang}

app=$(find ${SWDIR} -name mdvrapp*)	
fi