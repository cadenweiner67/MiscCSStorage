# Caden Weiner 
# Computer Science 260
# Bonus Assignment
.data
prompt1: .asciiz "Enter The Height in Feet\n"
prompt2: .asciiz "Enter The Height in Inches\n" 
prompt3: .asciiz "The Height is "
meters: .asciiz " Meters\n"
centimeters: .asciiz " Centimeters"

feetconvfact: .double 0.3048
inchesconvfact: .double 0.0254
meterconversion: .double 100.0
.text 
.globl main
main:  
l.d $f6, feetconvfact # loads the double value
l.d $f8, inchesconvfact # loads the double value
l.d $f10, meterconversion
# get height in feet


    li $v0, 4
    la $a0, prompt1 
    syscall
    
    li $v0, 7 # prompts the user for an integer input to load 1
    syscall
    mov.d $f4, $f0 # moves the input to $s0
# get height in inches
    li $v0, 4
    la $a0, prompt2 
    syscall
    
    li $v0, 7 # prompts the user for a double input to load 1
    syscall
    mov.d $f2, $f0 # moves the input to $s0

# s0 = height in feet. s1 = height in inches
# conversion into meters. 
# addi $f0, $zero, .3048 # conversion value feet to meters
    mul.d $f4, $f4, $f6
# addi $f0, $zero, .0254 # conversion value inches to meters
    mul.d $f2, $f2, $f8

    add.d $f12, $f4, $f2 # s0 contains the value in meters
    
    li $v0, 4
    la $a0, prompt3 # The height is 
    syscall

    li $v0, 3 # prints out what is in f12, a double
    syscall

    li $v0, 4
    la $a0, meters # meters
    syscall
# conversion into centimeters. Multiply answer in meters by 100 and change unit printed
    li $v0, 4
    la $a0, prompt3 # The height is 
    syscall

    mul.d $f12, $f12, $f10
    li $v0, 3 # prints out what is in f12, a double
    syscall

    li $v0, 4
    la $a0, centimeters # centimeters
    syscall

# Question Part B: Is it possible to use integer registers instead of float registers?
# Yes it is possible to use integer registers instead of float registers, 
# however a float ($f12) will need to be used to print a double.
# This can be done by converting the doubles into a integer format but it 
# would need to be converted back in order to print it as a double. However there can be issued
# as a result of each register holding a different sized value so there may
# be slight rounding differences. It is possible to use integer registers instead. 

