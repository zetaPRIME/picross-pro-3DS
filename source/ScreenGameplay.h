#pragma once

#include "starlight/ui/Form.h"

namespace picrosspro {
    class ScreenGameplay : public sl::ui::Form, public sl::ui::FormCreator<ScreenGameplay> {
        //
    public:
        ScreenGameplay();
        ~ScreenGameplay() override { };
        
        //void Update(bool focused) override;
    };
}
