/* func_L01_004593B8: 53 diff with the file's flags (L01_00457F00.c, @ps2as), about 12 compiles. Instructions and
   control flow are retail's (plain scalar D_L01_001E001C: lui/lw, then $gp in a delay slot); what differs is register
   allocation: a and b are in $s1/$s0 where retail has $s0/$s1 (b outranks a, regalloc.py), the count copies use
   $a0/$t0 where retail uses $t0/$t1 with -1 in $a0, the list checks end in move 0 / movz where retail has
   move x / movn, and the first loop tests its bound with slt against b's zero register where retail has blez. The
   pointer local for &p (assigned first) gives retail's $s2 = $sp. */
typedef int Q_004593B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004593B8;
extern u8 *D_L01_001E001C;
extern f32 func_L01_0040E518(void *, void *);

static __inline__ u8 *pick_004593B8(u8 *x, u8 **list, s32 n) {
    s32 i;
    s32 found = 0;
    for (i = 0; i < n; i++) {
        if (x == list[i]) {
            found = 1;
        }
    }
    if (found) {
        return 0;
    }
    return x;
}

u8 *func_L01_004593B8(s32 a0, u8 *obj, u8 **list, s32 *n, V_004593B8 *pos) {
    V_004593B8 p;
    V_004593B8 *pp;
    u8 *a;
    u8 *b;
    u8 *v;
    u8 *r;
    s32 i;
    s32 found;
    f32 da;
    f32 db;
    pp = &p;
    a = 0;
    b = 0;
    *(Q_004593B8 *)&p = *(Q_004593B8 *)pos;
    list[*n] = obj;
    (*n)++;
    v = *(u8 **)(obj + 0x68);
    if (*(s32 *)v != -1) {
        a = D_L01_001E001C + (*(s32 *)v << 8);
    }
    if (*(s32 *)(v + 4) != -1) {
        b = D_L01_001E001C + (*(s32 *)(v + 4) << 8);
    }
    if (a != 0 && b == 0) {
        return pick_004593B8(a, list, *n);
    }
    if (b != 0 && a == 0) {
        return pick_004593B8(b, list, *n);
    }
    db = 0.0f;
    db += func_L01_0040E518(b + 0x10, pp);
    if (3.0f < __builtin_fabsf(*(f32 *)(b + 0x18) - pp->z)) {
        db += 100.0f;
    }
    da = 0.0f;
    da += func_L01_0040E518(a + 0x10, pp);
    if (3.0f < __builtin_fabsf(*(f32 *)(a + 0x18) - pp->z)) {
        da += 100.0f;
    }
    r = b;
    if (da < db) {
        r = a;
    }
    return r;
}
