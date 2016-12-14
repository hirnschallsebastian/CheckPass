# CheckPass
The perfect tool to compare different password-guess strategies and generate graphs.      
Compare password guesses via stdin with a plaintext password list.     

# Features

* Output the number of correct guesses in fixed intervals in order to make generating graphs easy (you can set the interval)
* Test password guesses fast since calculating the hash is skipped
* Specify the maximum amout of guesses you want to try
* See all cracked and uncracked passwords
* Use multiple target dictionaries at once


# Usage
Compile using        
<code>g++ -std=c++11 checkpass.cpp -o checkpass</code>      

# How it works

checkPass uses a hashtable to compare all guesses it receives via stdin with a specified plaintext passwordlist.    
It outputs the number of correct guesses every few guesses (you can specify the interval) so that you can crate graphs easily.
