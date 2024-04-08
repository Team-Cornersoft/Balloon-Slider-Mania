#include "types.h"
#include "macros.h"

struct DMAVideoProps {
    const Texture *address;
    u32 compressedSize;
};

extern ALIGNED16 const struct DMAVideoProps course1_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course2_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course3_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course4_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course5_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course6_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course7_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course8_video_data[291];
extern ALIGNED16 const struct DMAVideoProps course9_video_data[1];
