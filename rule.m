function [if,body] = rule1()

  if_state = Z(i,j) == 1 && j > 1
body = Z(i+1,j+1) = 1; Z(i+1,j-1) = 1; Z(i+1,j) = 1;


end
