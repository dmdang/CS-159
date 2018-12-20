%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Programmers and Purdue Email Addresses:
%  1. santos45@purdue.edu
%  2. dangd@purdue.edu
%  3. askipwor@purdue.edu 
%
%  Lab #:10
%
%  Academic Integrity Statement:
%
%       We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have we provided access 
%       to our code to another. The project we are submitting
%       is our own original work.
%
%  Lab Division and Section: 11:30-1:20 Thursdays L08 17916
%
%  Program Description: This lab will read a file named labData and 
%
%  Listing and Commenting of All Variables Used:
%
%  Counter; Value that increments each time a perfect, abundant, or deficient number occurs
%  Total; Total number of values that are within the labData file
%  TestVariable; Value that gets passed through the calculation tests division properties and range of numbers from 1 up to the number being tested
%  Divisor; Divisor that increments through testvariable
%  Flag; Break statement that stops the print statement from printing more than once
%  fh; file handle that checks if file opened correctly or not   
%  number; Initial value within the labData file that we want to separate from rest of file
%  nextnumber; Value that we want to test for perfection, abundance, or deficience%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fh = fopen('labData','r');
counter = 0;                  
total = -1;
testvariable = 0;
divisor = 0;
flag = 0;

if(fh ~= -1)
  number = fscanf(fh,'%d',1);
  while(~feof(fh))
    divisor = 0;
    testvariable = 1;
    nextnumber = fscanf(fh,'%d',1);
    total = total + 1;
    for lcv = 1 : nextnumber / 2
      if(mod(nextnumber,testvariable) == 0)
        divisor = divisor + testvariable;
      end
      testvariable = testvariable + 1;
    end
    if((divisor == nextnumber) && (number == 3))
      counter = counter + 1;
    elseif((divisor > nextnumber) && (number == 2))
      counter = counter + 1;
    elseif((divisor < nextnumber) && (number == 1))
      counter = counter + 1;
    end
   if((divisor == nextnumber) && (number == 3))
      if(~flag)
        fprintf('Displaying perfect numbers:');
        flag = 1;
      end
      fprintf(' %d',nextnumber);
   elseif((divisor > nextnumber) && (number == 2))
      if(~flag)
        fprintf('Displaying abundant numbers:');
        flag = 1;
      end
      fprintf(' %d',nextnumber);
   elseif((divisor < nextnumber) && (number == 1));
      if(~flag)
        fprintf('Displaying deficient numbers:');
        flag = 1;
      end
     fprintf(' %d',nextnumber);
   end
 end
end 

fclose(fh);

fprintf('\nTotal Numbers Displayed: %d out of a total of %d numbers in file.\n',counter,total);
