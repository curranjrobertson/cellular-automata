
clear all;clc;close all
N = 1500;
x = 1:1:N+1;
y = 1:1:N+1;

Z = zeros(N+1,N+1);
Z(1, N/2) = 1;

for i = 1:N
  for j = 2:N
    if Z(i,j-1) == 1 && Z(i,j) == 1 && Z(i,j+1) == 1
      Z(i+1,j) = 0;
    elseif Z(i,j-1) == 1 && Z(i,j) == 1 && Z(i,j+1) == 0
      Z(i+1,j) = 0;
    elseif Z(i,j-1) == 1 && Z(i,j) == 0 && Z(i,j+1) == 1
      Z(i+1,j) = 0;
    elseif Z(i,j-1) == 1 && Z(i,j) == 0 && Z(i,j+1) == 0
      Z(i+1,j) = 1;
    elseif Z(i,j-1) == 0 && Z(i,j) == 1 && Z(i,j+1) == 1
      Z(i+1,j) = 0;
    elseif Z(i,j-1) == 0 && Z(i,j) == 1 && Z(i,j+1) == 0
      Z(i+1,j) = 1;
    elseif Z(i,j-1) == 0 && Z(i,j) == 0 && Z(i,j+1) == 1
      Z(i+1,j) = 1;
    elseif Z(i,j-1) == 0 && Z(i,j) == 0 && Z(i,j+1) == 0
      Z(i+1,j) = 0;
    end
  end
end

[X,Y] = meshgrid(x,y);
surf(X,Y,Z);

hold on;
view(2);


