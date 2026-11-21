// near miss: call sequence identical, but retail returns 1 (file L39_004C3278.c declares it void(): conflict), uses 16-byte save slots (frame 0x20) where the file's -fopt-stack gives 8-byte (0x10), and orders the last calls differently around delay slots (19 diff with --no-context)
extern void *func_L39_004DDD68(void);
extern void *func_L39_004DDBF0(void);
extern void *func_L39_004DDFB0(void);
extern void *func_L39_004DDDD8(void);
extern void *func_L39_004DF678(void);
extern void *func_L39_004DF688(void);
extern void *func_L39_004DF6B8(void);
extern void *func_L39_004DF668(void);
extern void func_L39_004DEA00(void *);
extern void func_L39_004DEA68(void *);
extern void func_L39_004DEBB8(char *, char *);
extern void func_L39_004DDAE8(void);
extern void func_L39_004DD668(void);
extern void func_L39_004EA3C8(void);
extern s32 func_L39_004C4F08(s64);
extern char D_L39_00475A00[];
extern char D_L39_00475A08[];
extern char D_L39_00475A18[];
extern char D_L39_00475A28[];
extern char D_L39_00475A30[];

s32 func_L39_004C32C8(void) {
    func_L39_004DEA00(func_L39_004DDD68());
    func_L39_004DEA00(func_L39_004DDBF0());
    func_L39_004DEA00(func_L39_004DDFB0());
    func_L39_004DEA00(func_L39_004DDDD8());
    func_L39_004DEA68(func_L39_004DF678());
    func_L39_004DEA68(func_L39_004DF688());
    func_L39_004DEBB8(D_L39_00475A00, D_L39_00475A08);
    func_L39_004DEBB8(D_L39_00475A00, D_L39_00475A18);
    func_L39_004DEA68(func_L39_004DF6B8());
    func_L39_004DEBB8(D_L39_00475A28, D_L39_00475A30);
    func_L39_004DEA68(func_L39_004DF668());
    func_L39_004DDAE8();
    func_L39_004C4F08(2);
    func_L39_004DD668();
    func_L39_004C4F08(1);
    func_L39_004EA3C8();
    return 1;
}
