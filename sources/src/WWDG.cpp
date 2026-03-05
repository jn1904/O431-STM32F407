#include "WWDG.h"

namespace O431 {
    WWATCHDOG::WWATCHDOG() {
        wwatchdog = &hwwdg;
        HAL_WWDG_Init(wwatchdog);
    }

    WWATCHDOG::~WWATCHDOG() {
        return;
    }

    void WWATCHDOG::feed_Dog() {
        HAL_WWDG_Refresh(wwatchdog);
    }
}
