/* functional: medium. compiled under level_39 (270 diff lines: stack 0x20 larger, regalloc); unsure: argument widths of func_003C6F90/func_003A9440 and exact packet field types; four 0x100-byte objects copied via func_0038CD28; gp slots D_001D6EB0..EE0_sda are 16-byte vectors */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005885C8;

typedef struct {
    u8 pad0[0x34];
    u16 flags;
} Obj_005885C8;

typedef struct {
    V4_005885C8 head;
    f32 rx;
    f32 ry;
    f32 rz;
    u8 pad1C[4];
    V4_005885C8 *tbl;
    f32 su;
    f32 sv;
    s32 count;
    s32 flag;
    u8 pad34[0xC];
    Obj_005885C8 *objs[4];
} Menu_005885C8;

typedef struct {
    u8 pad0[0x50];
    Menu_005885C8 *f50;
} Root_005885C8;

typedef struct {
    V4_005885C8 v[4];
    u32 col[4];
    struct { f32 u, v; } uv[4];
    s64 q500;
    s64 q508;
    s64 q510;
    s64 q518;
} Pkt_005885C8;

extern Root_005885C8 D_L39_0025CEC0;
extern s32 D_L39_0024BF5C;
extern u8 D_L39_0024DE20[];
extern f32 D_L39_0025D6C0[];
extern V4_005885C8 D_L39_00266740[4];
extern s64 D_L39_00240380;
extern V4_005885C8 D_001D6EB0_sda;
extern V4_005885C8 D_001D6EC0_sda;
extern V4_005885C8 D_001D6ED0_sda;
extern V4_005885C8 D_001D6EE0_sda;
extern f32 D_001D6E88_sda[4];
extern f32 D_001D6E98_sda[4];
extern s32 D_001D6F00_sda;

extern void func_L01_003EA9B8(void);
extern void func_L01_003EBF38(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_003C3860(void);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_L39_005ABFE8(void *, s32);
extern void func_0038CD28(void *, void *, s32);
extern void func_003881B0(s32, s32, f32);
extern void func_0013D5C0(void *);
extern void func_0013D708(f32, void *, void *);
extern void func_0013D7B0(f32, void *, void *);
extern void func_0013D660(f32, void *, void *);
extern void func_003861F0(void);
extern void func_L01_00423040(void);
extern void func_L39_005872D8(void);
extern void func_003A9440(s32, s64);
extern void func_L01_004C5D68(void);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00388258(void *, void *, s64);

void func_L39_005885C8(void) {
    u8 objbuf[4][0x100];
    u8 savedm[0x40];
    V4_005885C8 savedq;
    u8 newm[0x40];
    Pkt_005885C8 pkt;
    Menu_005885C8 *s;
    Obj_005885C8 *o;
    f32 keep;
    s32 count;
    s32 i;
    s32 j;
    s32 k;

    func_L01_003EA9B8();
    s = D_L39_0025CEC0.f50;
    if (s == 0) {
        func_003C3860();
        func_L01_003EBF38();
        return;
    }
    count = 0;
    func_003C36C0();
    func_003C3638();
    func_003C3660();
    for (i = 0; i < 4; i++) {
        o = s->objs[i];
        if (o == 0) {
            break;
        }
        func_003C6F90(o, 0x404040, 0xE, 0, 0);
        count++;
        o->flags |= 1;
    }
    func_L39_005ABFE8((void *)D_L39_0024BF5C, -1);
    for (i = 0; i < 4; i++) {
        o = s->objs[i];
        if (o == 0) {
            break;
        }
        o->flags &= 0xFFFE;
    }
    func_0038CD28(savedm, D_L39_0024DE20, 0x40);
    savedq = *(V4_005885C8 *)(D_L39_0024DE20 - 0x20);
    keep = D_L39_0025D6C0[0xB0 / 4];
    func_003881B0(8, 8, 1.0f);
    func_0013D5C0(newm);
    func_0013D708(s->rx, newm, newm);
    func_0013D7B0(s->ry, newm, newm);
    func_0013D660(s->rz, newm, newm);
    func_0038CD28(D_L39_0024DE20, newm, 0x40);
    *(V4_005885C8 *)(D_L39_0024DE20 - 0x20) = s->head;
    func_003861F0();
    D_L39_00266740[0] = D_001D6EB0_sda;
    D_L39_00266740[3] = D_001D6EE0_sda;
    D_L39_00266740[2] = D_001D6EC0_sda;
    D_L39_00266740[1] = D_001D6ED0_sda;
    if (count == 1) {
        func_L39_005ABFE8(s->objs[0], 1);
    } else {
        for (i = 0; i < 4; i++) {
            o = s->objs[i];
            if (o != 0) {
                func_0038CD28(objbuf[i], o, 0x100);
            }
        }
        func_L39_005ABFE8(objbuf, count);
    }
    func_L01_00423040();
    D_L39_0025D6C0[0xB0 / 4] = keep;
    func_L39_005872D8();
    func_0038CD28(D_L39_0024DE20, savedm, 0x40);
    *(V4_005885C8 *)(D_L39_0024DE20 - 0x20) = savedq;
    func_003861F0();
    func_003A9440(0x42, 0x8000000044LL);
    func_003A9440(8, 5);
    func_L01_004C5D68();
    func_003C3690();
    func_003C3800();
    s = D_L39_0025CEC0.f50;
    if (s->count > 0) {
        j = 0;
        k = 0;
        do {
            pkt.q500 = 5;
            pkt.q518 = 0x8000000044LL;
            pkt.col[0] = D_001D6F00_sda;
            pkt.col[3] = D_001D6F00_sda;
            pkt.col[2] = D_001D6F00_sda;
            pkt.col[1] = D_001D6F00_sda;
            pkt.q510 = 0xFF90000000000260LL;
            pkt.q508 = D_L39_00240380;
            for (i = 0; i < 4; i++) {
                pkt.uv[i].u = s->su * D_001D6E88_sda[i] + 0.5f;
                pkt.uv[i].v = s->sv * D_001D6E98_sda[i] + 0.5f;
                pkt.v[i] = s->tbl[k + i];
            }
            func_003D2DA0(&pkt, 0, 0);
            if (s->flag != 0) {
                func_00388258(s, &s->tbl[k], D_L39_00240380);
            }
            j++;
            k += 4;
            s = D_L39_0025CEC0.f50;
        } while (j < s->count);
    }
    func_L01_003EBF38();
}
