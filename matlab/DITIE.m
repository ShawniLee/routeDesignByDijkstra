function [price,output] = DITIE( start,ter)
A=importdata('站点信息1.xlsx');



B=importdata('Name.xlsx');%得到节点矩阵B
N=length(B);%得到节点数量
M=length(A.textdata(:,1));
weight=importdata('Map.xlsx');
 
a=find(strcmp(start,B)==1);%起点站对应的行数
b=find(strcmp(ter,B)==1);%终点站对应的列数

if ~isempty(a)&&~isempty(b)
[dist,path]=dijkstra(weight,a,b);

c=length(path);
for u=1:c
way(u)=B(path(u));
end


for u=1:c-1
for j=1:M
if  strcmp(way(u),A.textdata{j,1})==1&&strcmp(way(u+1),A.textdata{j,2})==1||strcmp(way(u),A.textdata{j,2})==1&&strcmp(way(u+1),A.textdata{j,1})==1
line{1,u}=A.textdata{j,3};
end
end
end

if c>5
l=length(line); m=1;
for i=1:l-1
  
if strcmp(line{1,i},line{1,i+1})==0
change1(m)=way(i);%找到换乘的起点
change2(m)=way(i+1);%找到换乘的下一站
m=m+1;
end
end


d=length(unique(line))-1;
for j=1:d

for e=1:286
    if strcmp(change1{j},B{e})==1
     change1num(j)=e;
    end
end
end
for q=1:d
for e=1:286
    if strcmp(change2{q},B{e})==1
     change2num(q)=e;
    end
end
end
weight(change1num,change2num)=inf;%修改邻接矩阵的换乘站路径权重
weight2=weight;
[dist,path]=dijkstra(weight2,a,b);%再次运行

r=length(path);
for f=1:r
way(f)=B(path(f));
end

for f=1:r-1
for g=1:M
if  strcmp(way(f),A.textdata{g,1})==1&&strcmp(way(f+1),A.textdata{g,2})==1||strcmp(way(f),A.textdata{g,2})==1&&strcmp(way(f+1),A.textdata{g,1})==1
line{1,f}=A.textdata{g,3};
end
end
end
if dist~=0
dista(j,1)=dist;
linea(j,:)=line;
end

for v=length(linea(:,1))
o=find(min(length(unique(linea(v,:)))));
lineb=line(o,:);
distb=dista(o,1)+3.4*d;
end
end

if c<5||c==5
    lineb=line;
    distb=dist;
end
 output=unique(lineb,'stable');

if distb<6||distb==6
    price=3;
end
 if distb>6&&distb<12||distb==12
        price=4;
 end
 if distb>12&&distb<22||distb==22
        price=5;
 end
 if distb>22&&distb<32||distb==32
        price=6;
 end
 if distb>32&&distb>32
        price=ceil((distb-32)/20)+6;
 end
end
if isempty(a)
    output='起始站点不存在';
    price=0;
end
if isempty(b)
    output='终点站点不存在';
    price=0;
end
 disp(output);

end

    