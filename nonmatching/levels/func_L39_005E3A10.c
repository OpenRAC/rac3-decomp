/* func_L39_005E3A10: p2 near miss (w8), 2 diff. rac2 twin func_L14_003DE990 (portrun was wrong).
   Only the order of 'sll a0,a0,9' vs 'addiu v0,v0,lo(D_L39_002B5E70)' differs (retail sll first).
   Tried: ptr+off, struct array, 2-D array, unsigned, locals. */
extern void func_0011D534(void *, int, int);
extern unsigned char D_L39_002B5E70[];
void func_L39_005E3A10(int arg0) { func_0011D534((arg0 << 9) + D_L39_002B5E70, 0, 0x200); }
