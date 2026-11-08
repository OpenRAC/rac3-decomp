#include "common.h"

struct HudTexCounts {
    unsigned char pad0[0x14];
    int mid_ends[8];
    int ends[16];
    int loaded[16];
};
struct HudBank {
    int unk0;
    int off4;
    int off8;
    int offC;
    int off10;
    unsigned char pad14[0x40];
    int has54;
    int size58;
    int has5C;
    int has60;
    int has64;
    unsigned char pad68[0x2C];
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
};
struct HudTexPage {
    unsigned int source_address;
    unsigned short gs_block_offset;
    unsigned char width_log2;
    unsigned char height_log2;
};
struct HudState {
    int serial;
    int unk4;
    int unk8;
    int z;
    int heap_cur;
    int heap_end;
    union {
        struct HudTexCounts *counts;
        struct HudBank *bank;
    } header;
    void *anim_defs;
    void *frame_refs;
    struct HudTexPage *image_pages;
    struct HudTexPage *palette_pages;
};

/* localdecomp:start func_L39_0059C088 */
extern struct HudState D_L39_0024BCE0 __attribute__((section(".sdata")));
extern void func_00392FD0(int, int);
extern int D_001FC488[];
extern int D_001D7420_sda;
extern void func_L39_0059D6B0(unsigned int, int, int, int, int, int);

void func_L39_0059C088(int bank, int base, int immediate)
{
    struct HudTexCounts *counts;
    int address;
    int bank_offset;
    int first;
    int end;
    int i;
    int page;
    int width_log2;
    int height_log2;
    int size;
    if (D_L39_0024BCE0.header.counts->loaded[bank] == 0) {
        func_00392FD0(0, base);
        address = D_001FC488[0];
    } else {
        address = D_001FC488[0];
    }
    counts = D_L39_0024BCE0.header.counts;
    bank_offset = bank << 2;
    first = bank == 0 ? 0 : counts->ends[bank - 1];
    i = first;
    end = *(int *)((unsigned char *)D_L39_0024BCE0.header.counts + bank_offset + 0x34);
    do {
        for (; i < end; i++) {
            page = address >> 8;
            width_log2 = D_L39_0024BCE0.image_pages[i].width_log2;
            height_log2 = D_L39_0024BCE0.image_pages[i].height_log2;
            size = 1 << (width_log2 + height_log2);
            func_L39_0059D6B0(D_L39_0024BCE0.image_pages[i].source_address, page, 0x1B, width_log2,
                          height_log2, immediate);
            address += size * 4;
            D_L39_0024BCE0.image_pages[i].gs_block_offset = page;
            D_001D7420_sda = address;
        }
    } while (0);
}
/* localdecomp:end func_L39_0059C088 */
