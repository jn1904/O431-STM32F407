#ifndef F407_WWDG_H
#define F407_WWDG_H
#ifdef __cplusplus
extern "C" {
#endif

#include "wwdg.h"
    namespace O431 {
        class WWATCHDOG {
        public:
            WWATCHDOG();
            ~WWATCHDOG();

            void feed_Dog();

        private:
            WWDG_HandleTypeDef* wwatchdog;

        };
    }
#ifdef __cplusplus
}
#endif
#endif //F407_WWDG_H