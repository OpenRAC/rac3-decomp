/* functional: high. compiles under level_39 flags; offsets/constants checked against asm; not byte exact (register choice) */
typedef struct {
    u8 pad0[0x34];
    u16 flags;
    u8 pad36[0x32];
    void *f68;
    u8 pad6C[0x3E];
    s16 type;
} Obj_0059E8D0;

typedef struct {
    u8 pad0[0x44];
    s16 count;
    u8 pad46[0x15A];
    Obj_0059E8D0 *objs[1];
} Tbl_0059E8D0;

extern Tbl_0059E8D0 D_L39_0025CEC0;
extern u8 D_L39_00242C34[];
extern u8 D_L39_00242C38[];
extern u8 D_001D7520_sda[];
extern void func_L01_003E32F0(void);
extern void func_L01_00424168(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00451DB8(f32, void *, u32, u32);

void func_L39_0059E8D0(void) {
    s32 i;
    Obj_0059E8D0 *o;

    func_L01_003E32F0();
    for (i = 0; i < D_L39_0025CEC0.count; i++) {
        o = D_L39_0025CEC0.objs[i];
        if (o == 0) {
            continue;
        }
        if (o->type == 0xE29) {
            o->flags |= 0x800;
        }
        if (o->type == 0xFA0) {
            if (o->f68 == 0) {
                continue;
            }
            func_L01_00451DB8(0.0733038336f, (u8 *)o->f68 + 0xC, 0x80AAAAD2, 0x80396464);
        } else if (o->type == 0x1DEE || o->type == 0x19BC) {
            func_L01_00451DB8(0.0383972451f, D_001D7520_sda, 0x80505080, 0x80404038);
        } else if (o->type == 0x1977) {
            func_L01_00451DB8(0.0453785658f, D_L39_00242C34, 0x8080AAAA, 0x80464646);
        } else if (o->type == 0x1766) {
            func_L01_00451DB8(0.132645041f, D_L39_00242C38, 0x80AAAAFF, 0x80646496);
        } else if (o->type == 0x195B || o->type == 0x1B58 || o->type == 0x195C || o->type == 0x175A) {
            func_L01_00404808(func_L01_00424168, o);
        }
    }
}
