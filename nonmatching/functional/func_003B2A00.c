/* functional: high. US draft verified against PAL asm (stores order irrelevant: build a 24-byte struct {a,b,c-(p->0x48),d} and pass to func_003B2590 with D_1DA0B4+0x48). */
typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA0B4[];
extern void func_003B2590(u8 *, S_3AD0A0 *);
void func_003B2A00(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_003B2590(D_001DA0B4[0] + 0x48, &s);
}
