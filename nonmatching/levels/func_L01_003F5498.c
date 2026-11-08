/* func_L01_003F5498: near miss 13 diff (Sonnet w3, p2w1)
   file: src/levels/shared/L01_003F5498.c, 72 bytes
   needs --as ps2as; same ops but lui/div.s/addiu scheduling order differs
*/
typedef struct { char pad[0x128]; float f128; int f12c; char pad2[0x460 - 0x130]; } E;
extern float D_L01_001DF950[];
extern E D_L01_001E2A40[];

void func_L01_003F5498(int i, float x)
{
    E *e = D_L01_001E2A40 + i;
    float r = 1.0f / x;
    D_L01_001DF950[i] = 1.0f;
    e->f12c = 0;
    e->f128 = r;
}
