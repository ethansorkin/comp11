1. In Lab 0, we used the editor Kate to write our program files. When programming on a Unix machine, there are lots of other editors out there (e.g., Emacs, vim, Nano, etc.). 

For this assignment, research two additional editors that run on Linux. Of the 3 you’ve seen (Kate, plus the two you just researched) describe which one you’d prefer to use for your programming work. Justify your answer.
The two additional editors I researched are Vi/Vim Editor and Gedit. Of the three editors that I have seen, I would prefer to use Kate, as it is the most easily accessible at Halligan. Although, the other two systems have some advantages, but I would rather use the same editor for all my codes, and since Kate is used in the lab, I want to become very comfortable with it.  In addition, Kate includes advanced editor features, applications features, programming features, text highlighting features, backup features and search and replace features. It is easy to organize files on Kate, using the “Project” and “Document” tabs on the left side of its interface.

Although I will not chose to use them, Vi/Vim and Gedit have many benefits. Vi/Vim is widely used text editors among System Administrators and programmers, which is why it is often referred to as a programmer’s editor. It also enables syntax highlighting when writing code or editing configuration files.

Gedit is a user-friendly and highly pluggable editor. It supports UTF-8, has highly customizable syntax highlighting, allows for remote editing, and can search and replace text.


2. Complete self-test exercises 16-20 from page 29 of your text book. 

16. C++ is easy to understand
17. It tells the computer to start a new line
18. It means that “peas_per_pod” is a variable that stores an input assigned by the user
19. The variable “total_peas” is equal to the product of the assigned values for the variables “number_of_pods” and “peas_per_pod”
20. It tells the computer where to find the information about the items in your program (in this case it is found in the library, iostream)



3. Use pseudocode to describe how to make a Peanut Butter & Jelly sandwich. 

-(If bread is not sliced) Take a serrated knife in your hand.
	-Cut two ½ inch slices of bread from the loaf
-(If bread is sliced begin here) Place two slices on the table in front of you
-(If PB jar is not open) Take the PB jar in your hand
	-Twist the lid clockwise and remove it from the jar
	-Place jar and lid separately on the table
-(If PB is open continue here) Take butter knife in hand
-Place edge of knife in PB jar and scoop out 2 tablespoons of PB
-Spread the PB on the surface of one entire slice of bread that was previously placed on the table
-(If jelly jar is not open) Take the jelly jar in your hand
	-Twist the lid clockwise and remove it from the jar
	-Place jar and lid separately on the table
-(If jelly is open continue here) Take butter knife in hand
-Place edge of knife in jelly jar and scoop out 2 tablespoons of jelly
-Spread the jelly on the entire surface of the unused slice of bread that was previously placed on the table
-Take either slice of bread in your hand and place it on top of the other slice so that the PB and jelly are touching, and no PB or jelly is exposed.



4. While you were working on the programming component of this assignment, describe one issue that your compiler told you about. Was it a warning or an error? How did you fix it?

Errors and warnings both indicate issues with your program. However, warnings are not as significant mistakes, as the program will still compile with warnings, but may be very messy.  With an error, your code will not compile because the mistake is big enough that it does not work at all.

One issue I ran into was with my trick 99 program was as follows: 

/usr/sup/lib/gcc/x86_64-unknown-linux-gnu/5.4.0/../../../../include/c++/5.4.0/x86_64-unknown-linux-gnu/bits/c++config.h:194:1: error: 
      expected unqualified-id
namespace std

This was a compiling error that prevented my program from compiling. It was very frustrating because it told me that the issue was in the “using namespace std;” line.  I tirelessly reviewed this one line and could not find out what was wrong with it.  After a long period of frustration, I finally decided to review the other parts of the program. It turned out that the issue was in the very first line, where I began my comment with an asterisk instead of a forward slash. I deleted the asterisk and the error was fixed.



