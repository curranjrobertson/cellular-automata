function [statement,body] = rule1()

statement = 'Z(i,j) == 1 && j > 1';
body = 'Z(i,j+1) = 1';


end
