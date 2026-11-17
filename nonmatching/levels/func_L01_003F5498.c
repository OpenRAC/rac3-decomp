/* func_L01_003F5498: 3 diff with the file's flags and the div.s padding line `func_L01_003F5498 2` in
   config/levels/divs_nops.txt (not added: the function is not matched). Every instruction and register is
   retail's; only the order of two address halves after the mult differs: retail issues lui $a1,%hi(D_L01_001E2A40)
   first, then sll $a0,$a0,2 and lui $v0,%hi(D_L01_001DF950); this C issues the D_L01_001DF950 lui first. Pointer
   locals for both rows took it from 4 to 3; all six store orders, index forms (&a[i], a + i, char offsets,
   unsigned i), N mode and Ps2EeAs give the same or worse. */
typedef struct { char pad[0x128]; float f128; int f12c; char pad2[0x460 - 0x130]; } E;
extern float D_L01_001DF950[];
extern E D_L01_001E2A40[];

void func_L01_003F5498(int i, float x)
{
    E *e = D_L01_001E2A40 + i;
    float *f = D_L01_001DF950 + i;
    float r = 1.0f / x;
    *f = 1.0f;
    e->f12c = 0;
    e->f128 = r;
}
