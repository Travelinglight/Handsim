# README.md
---
### format_instructions.py:
用于将格式指令转换成汇编代码，直接 python format_instrutions.py 即可，会自动读入 origim.mips 输出结果至origin.mips

### mips.py:
用于将汇编代码转成机器码，直接 python mips.py 即可，会自动读入 origin.mips 输出结果至 machineCode.mips

### dismips.py:
用于将机器吗转换成汇编代码，直接 python dismips.py 即可，会自动读入 machineCode.mips 输出结果至 disassembleCode.mips

### formatDict.py:
这是将格式指令转换成汇编代码时的字典，不用进行编译，会自动被 import 到 mips.py 里面

### assembleDict.py:
这是将汇编代码转换成机器码时的字典，不用进行编译，会自动被 import 到 mips.py 里面

### disassembleDict.py:
这是将机器码转换成汇编代码时的字典，不用进行编译，会自动被 import 到 dismips.py 里面


#### PS: 为了便于调试，暂时使用了非二进制文件的普通字符串输出，正式合在一起时再做商议与修改

# 目前支持指令：

* R类型 全部
* I类型 全部
* J类型 全部
* 伪指令 全部
* 格式指令 部分完成

# 目前测试样例与结果：

### 汇编代码输入：
 
**input: test.txt**

``` 

 add $s0, $t0  , $t1 #dededefewf
shit:   Sub    $s0, $      s0, $t0  # hahaha
bEq $s0, $  zero  , rr   
beq  $s1, $s0, fuck
    sW $S1, 2(  $t0) #defe efwfwef (f we)
rr:    lw $v0, 2*(3-1)( $t0  )#ha
j  0x03   
5*8:    j   shit
j 5*8

addi $t0 $zero 1-3+4*(3-1)
add $t1 $t0 $s1
fuck:    BLT $s0, $t0, rr
BGE $t1, $s1, fuck
syscall

```

### 机器码输出：

**output: out**

``` 

00000001000010011000000000100000
00000010000010001000000000100010
00010010000000000000000000000011
00010010001100000000000000001000
10101101000100010000000000000010
10001101000000100000000000000100
00001000000000000000000000000011
00001000000000000000000000000001
00001000000000000000000000000111
00100000000010000000000000000110
00000001000100010100100000100000
00000010000010000000100000101010
00010100001000001111111111111001
00000001001100010000100000101010
00010000001000001111111111111101
00000000000000000000000000001100


```

### 反汇编代码过程结果：

**output: back.txt**

``` 

             add $s0, $t0, $t1
mark_1   :   sub $s0, $s0, $t0
             beq $s0, $zero, mark_5
mark_3   :   beq $s1, $s0, mark_11
             sw $s1, 2($t0)
mark_5   :   lw $v0, 4($t0)
             j mark_3
mark_7   :   j mark_1
             j mark_7
             addi $t0, $zero, 6
             add $t1, $t0, $s1
mark_11  :   slt $at, $s0, $t0
             bne $at, $zero, mark_5
             slt $at, $t1, $s1
             beq $at, $zero, mark_11
             syscall


```

# 待完成：

* 错误提示
