/* Level 7 near miss: 4 differences, all the flag lbu/bnez register in the
   case 2 and case 1 tests ($v1 vs retail $v0). local-alloc does not fuse the
   lbu destination with the address pseudo that dies at the load. Case order in
   the source (2/0/1) already gives retail's body layout. Not linked. */
typedef struct { u8 pad0[0x68]; u8 *p68; } O_003C12A8;

extern u8 D_00142CBE[];
extern u8 D_001426F5[];
extern u8 D_001D553D[];
extern u8 D_001D5551[];
extern void func_00437DA0(void);
extern void func_L07_003C1E48(u8 *);
extern void func_L07_003C1E80(u8 *);

s32 func_L07_003C12A8(O_003C12A8 *arg0, s32 arg1) {
    u8 *p = arg0->p68;
    s32 r = 0;

    switch (arg1) {
    case 2:
        if (D_001D5551[0] != 0) break;
        return 1;
    case 0:
        if (D_00142CBE[0] != 0) break;
        *(void **)(p + 0x2C) = func_L07_003C1E48;
        D_001426F5[0] = 1;
        func_00437DA0();
        r = 1;
        break;
    case 1:
        if (D_001D553D[0] != 0) break;
        *(void **)(p + 0x2C) = func_L07_003C1E80;
        r = 1;
        break;
    }
    return r;
}
