/* func_L39_005C8CA8: near miss (w5 wave 3), from rac2 func_002BDBC0. Compiles with --as ps2as; only diff is the missing nop;nop before div.s (divs_nops) and the shift it causes.
   Levels 39-53 (15), flags -O2 -G8 -fopt-stack -mno-check-zero-division.
   Port: rac2 Effect layout, 0x74/0x44 consts, float 0.00049600005f. */
typedef int u128_t __attribute__((mode(TI)));
extern char *func_003CD108(int);
extern int func_19D510(void);
extern unsigned char *D_L39_00296870[];

void func_L39_005C8CA8(void *pos, void *dir, int color, int flags, int frames, float size)
{
    char *e;
    char *p;
    float d;

    e = func_003CD108(0x16);
    if (e != 0) {
        *(int *)(e + 4) = color;
        *(float *)(e + 0xC) = size * 0.2f;
        *(unsigned char *)(e + 1) = 0;
        *(unsigned char *)(e + 9) = 0x74;
        *(unsigned char *)(e + 3) = 0x44;
        *(unsigned char *)(e + 8) = func_19D510();
        p = e + 0x20;
        *(unsigned char *)(e + 2) = **D_L39_00296870;
        *(short *)(e + 0xA) = frames;
        *(short *)(p + 0x18) = frames;
        d = size - *(float *)(e + 0xC);
        *(int *)(p + 0x10) = color;
        *(int *)(p + 0x14) = flags;
        *(float *)(p + 0x1C) = d / (float)frames;
        *(u128_t *)p = *(u128_t *)dir;
        *(u128_t *)(e + 0x10) = *(u128_t *)pos;
        *(float *)(p + 0xC) = 0.00049600005f;
    }
}
