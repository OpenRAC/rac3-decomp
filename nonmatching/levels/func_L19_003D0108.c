/* func_L19_003D0108: MATCHES under --mode N (plain or ps2as), 2 diff in the file's mode S (lui/addiu vs sd $ra order).
   File L19_003CFC58.c is mode S + @ps2as and its other C function func_L19_003D0130 matches only there (40 diff in mode N),
   so the file cannot take mode N: needs the function moved to its own file/part or a split. */
extern char D_L19_001D64E0[];
extern int func_L01_0040C948(void *, void *);

int func_L19_003D0108(char *obj) {
    return func_L01_0040C948(*(char **)(obj + 0x68) + 0x90, D_L19_001D64E0);
}
