file=dir('1-2\*.csv');
A=cell(31, 2);
B=cell(30, 2);
for r=1:31
    A{r, 1}=410+10*r;
end
for r=1:30
    B{r, 1}=410+10*r;
end
file_name=cell(1,1);
file_data=cell(2,1);
for i=1:size(file,1)
    file_name{i,1}=strcat('1-2\',file(i).name);
    file_data{i,1}=csvread(file_name{i,1}, 1 ,1);
end 

for j=1:31
    sum=0;
    for i=1:size(file, 1)
        sum = sum + file_data{i, 1}(j);
    end
    A{j, 2}=sum/size(file, 1);
end

for t=1:30
    B{t, 2}=(A{t+1, 2}-A{t, 2})/10;
end

csvwrite('data_diff\1-2.csv', B, 1, 0);