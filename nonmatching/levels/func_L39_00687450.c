/* func_L39_00687450: near miss 7 diff (w2 p2w2). 184 bytes, 1 level. From asm (7 int args; uses a0,a2,a4,a5,a6). Remaining: callee-saved reg order (o=s4,a6=s3 in retail) and clamp as slti+movn (ours slt/movz). */
typedef struct {
    u8 pad[0x394];
    int f394;
} S_Inner;
typedef struct {
    u8 pad[0xB0];
    S_Inner *fB0;
} S_Outer;
extern void func_L39_006AB6D0(S_Inner *);
extern void func_L39_006AB700(S_Inner *, int);
extern void func_L39_006AB778(S_Inner *, int);
extern void func_L39_006AB6F8(S_Inner *, int);
extern void func_L39_00687268(S_Outer *, int);

int func_L39_00687450(S_Outer *o, int a1, int a2, int a3, int a4, int a5, int a6)
{
    S_Inner *p = o->fB0;
    int v;
    int t;
    if (p != 0) {
    func_L39_006AB6D0(p);
    func_L39_006AB700(p, a2);
    func_L39_006AB778(p, a5);
    t = a4 - 1;
    v = 199;
    if (t < 200)
        v = t;
    p->f394 = v;
    func_L39_006AB6F8(p, a6);
    func_L39_00687268(o, 0x13);
    return a2;
    }
    return 0;
}
