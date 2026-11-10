#include "common.h"

LINKER_REMNANT("asm/levels", func_L19_0044A0B0);

INCLUDE_ASM("asm/levels", func_L19_0044A0C0);

/* localdecomp:start func_L19_0044A568 */
typedef struct RouteNode_0044A568 {
    /* 0x00 */ s32 path;
    /* 0x04 */ u8 neighbors[4];
    /* 0x08 */ u8 portals[4];
    /* 0x0C */ u16 flags;
    /* 0x0E */ u8 pad0E[0x12];
} RouteNode_0044A568;

extern char *D_L19_0021D500[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L19_0044A9A0(f32 *, RouteNode_0044A568 *, s32, s32 *);
extern f32 func_L19_0044A860(char *, char *, f32 *, f32, f32);

s32 func_L19_0044A568(f32 *position, f32 *target, f32 *heading, RouteNode_0044A568 *nodes, s32 count, s32 *sourceNode, s32 *targetNode, f32 override, f32 margin) {
    u8 visited[256];
    s32 i, j, found, portal, step, routeDepth;
    s32 layer;
    char *path;
    f32 angle;
    *heading = func_0038D160(target[0] - position[0], target[1] - position[1]);
    if (override != 0.0f)
        *heading = func_0038DAB8(override, *heading);
    if (!func_L19_0044A9A0(position, nodes, count, sourceNode))
        return 0;
    if (!func_L19_0044A9A0(target, nodes, count, targetNode))
        return 0;
    if (nodes[*targetNode].flags & 1)
        return 0;
    if (*sourceNode == *targetNode)
        return 1;
    {
        s32 clear;
        for (clear = 0; clear < count; clear++)
            visited[clear] = 0;
    }
    found = -1;
    portal = -1;
    visited[*targetNode] = 1;
    for (layer = 1; layer < 50; layer++) {
        for (i = 0; i < count; i++) {
            if (visited[i] == layer) {
                for (j = 0; j < 4; j++) {
                    u32 neighbor = nodes[i].neighbors[j];
                    if (!(neighbor & 0x80) && !visited[neighbor] && (((u8)nodes[neighbor].flags ^ 1) & 1)) {
                        visited[neighbor] = layer + 1;
                        if (neighbor == *sourceNode) {
                            portal = nodes[i].portals[j];
                            found = i;
                        }
                    }
                }
            }
            if (found != -1)
                break;
        }
        if (found != -1)
            break;
    }
    if (found == -1)
        return 0;
    path = D_L19_0021D500[nodes[found].path];
    angle = *heading;
    routeDepth = visited[found];
    if (routeDepth >= 3) {
        s32 edge;
        step = routeDepth - 1;
        for (edge = 0; edge < 4; edge++) {
            if (visited[nodes[found].neighbors[edge]] == step) {
                s32 offset = nodes[found].portals[edge] * 16;
                angle = func_L19_0044A860(path + (offset + 0x10), path + (offset + 0x20), position, angle, margin);
                break;
            }
        }
    }
    *heading = func_L19_0044A860(path + (portal * 16 + 0x10), path + (portal * 16 + 0x20), position, angle, margin);
    return 1;
}
/* localdecomp:end func_L19_0044A568 */

INCLUDE_ASM("asm/levels", func_L19_0044A860);

/* localdecomp:start func_L19_0044A9A0 */
extern s32 func_L01_004463F8(f32 *p, f32 *v, s32 n);
extern f32 func_0038CF38(void *a, void *b);

/* from rac2-decomp's func_L02_0032EDD8 */
s32 func_L19_0044A9A0(f32 *point, RouteNode_0044A568 *nodes, s32 count, s32 *index) {
    s32 i;
    if (*index != -1) {
        char *entry;
        s32 n;
        entry = D_L19_0021D500[nodes[*index].path];
        n = *(s32 *)entry;
        entry += 0x10;
        if (func_L01_004463F8(point, (f32 *)entry, n) != 0)
            return 1;
    }
    for (i = 0; i < count; i++) {
        if (i != *index
            && func_0038CF38(point, (char *)&nodes[i] + 0x10) <= *(f32 *)((char *)&nodes[i] + 0x1C)) {
            char *entry;
            s32 n;
            entry = D_L19_0021D500[nodes[i].path];
            n = *(s32 *)entry;
            entry += 0x10;
            if (func_L01_004463F8(point, (f32 *)entry, n) != 0) {
                *index = i;
                return 1;
            }
        }
    }
    *index = -1;
    return 0;
}
/* localdecomp:end func_L19_0044A9A0 */

LINKER_REMNANT("asm/levels", func_L19_0044AAD8);
