/* functional: high. compiles under level_39; differs only in register allocation/loop shape (107 diff lines); names: func_003932C0 is allocator(size,0,name,line) */
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    s32 f20;
    struct { s32 size; s32 pad; } ent[5];
} Hdr_0059F5F8;

typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x40];
    s32 f54;
    s32 f58;
    u8 pad5C[0x38];
    s32 f94;
} Blob_0059F5F8;

extern Hdr_0059F5F8 *D_L39_00240290 __attribute__((section(".data")));
extern s32 D_L39_0025F680[];
extern u8 D_L39_00242D60[];
extern u8 D_L39_00242D70[];
extern u32 D_L39_0024BD20[5] __attribute__((section(".data")));
extern Blob_0059F5F8 *D_L39_0024BCF8 __attribute__((section(".data")));
extern void *D_L39_0024BCFC __attribute__((section(".data")));
extern void *D_L39_0024BD00 __attribute__((section(".data")));
extern void *D_L39_0024BD04 __attribute__((section(".data")));
extern void *D_L39_0024BD08 __attribute__((section(".data")));

extern void *func_003932C0(s32, s32, void *, s32);
extern void func_0038CD28(void *, void *, s32);
extern void func_003990F0(s32, s32);
extern s32 func_L39_005F4188(void *, s32, s32, void *);
extern void func_L39_0059C088(s32, s32, s32);
extern void func_001264E0(s32);
extern void func_00392FD0(s32, void *);
extern void func_00393138(void);

void func_L39_0059F5F8(void) {
    Hdr_0059F5F8 *hdr = D_L39_00240290;
    Blob_0059F5F8 *blob;
    s32 size;
    s32 base;
    s32 n;
    s32 i;

    i = 0;
    do {
        D_L39_0024BD20[i] = (hdr->ent[i].size + 0x3F) & 0xFFFFFFC0;
        i++;
    } while (i < 5);
    size = (hdr->f1C + 0x3F) & 0xFFFFFFC0;
    blob = func_003932C0(size, 0, D_L39_00242D60, 0x39E);
    func_0038CD28(blob, (u8 *)hdr + hdr->f18, size);
    D_L39_0024BCF8 = blob;
    D_L39_0024BCFC = (u8 *)blob + blob->f4;
    base = D_L39_0025F680[4] + 0x30000;
    D_L39_0024BD00 = (u8 *)blob + blob->f8;
    D_L39_0024BD08 = (u8 *)blob + blob->fC;
    D_L39_0024BD04 = (u8 *)blob + blob->f10;
    if (blob->f54 != 0) {
        n = ((hdr->ent[0].size + 0x3F) & 0xFFFFFFC0) >> 4;
        func_003990F0(0, base);
        D_L39_0024BCF8->f94 = func_L39_005F4188((u8 *)hdr + hdr->f20, n, n, D_L39_00242D70);
        func_L39_0059C088(0, base, 1);
    }
    blob = D_L39_0024BCF8;
    if (blob->f58 != 0) {
        void *p = func_003932C0(blob->f58, 0, D_L39_00242D60, 0x3CE);
        func_003990F0(1, (s32)p);
        func_001264E0(0);
        func_00392FD0(1, p);
    }
    func_00393138();
}
