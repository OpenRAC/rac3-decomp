/* func_L20_004024E8: near miss (w5 wave 3), from asm (--as ps2as). Params struct on stack; a2=1 constant is shared between the call arg and p.i20 store in retail and early in the schedule, not reproduced (38+ diff, mostly a shift). Level 20 only. */
typedef union { int q __attribute__((mode(TI))); float f[4]; } Vector;
typedef struct {
    Vector v;
    char *owner;
    int i14;
    unsigned char b18, b19;
    unsigned short h1A;
    float f1C;
    int i20;
} Params;
extern Vector D_L20_001D66B0;
extern void func_0038CF68(void *, void *, int, float);
extern void func_003D4D00(void *, int, int, void *, float);

void func_L20_004024E8(char *obj, char *src)
{
    Params p;

    p.f1C = *(float *)(src + 0x34);
    p.i14 = *(int *)(src + 0x3C);
    p.v.q = D_L20_001D66B0.q;
    p.i20 = 1;
    p.owner = obj;
    func_0038CF68(&p, &p, 1, 1.0f);
    p.v.f[3] = 5627.9248f;
    p.b18 = 3;
    p.b19 = 2;
    p.h1A = *(unsigned short *)(obj + 0xAA);
    func_003D4D00(obj + 0x10, 0, 0, &p, *(float *)(src + 0x38));
}
