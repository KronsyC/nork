// Copyright (c) 2023 Samir Bioud
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef NORK_INVENTORY_H
#define NORK_INVENTORY_H

#include "item.h"
#include <cstdint>
#include <memory>

namespace nork {
class Inventory {
    using SLOTIDX_T = uint16_t;

    SLOTIDX_T nslots;

    ///
    ///
    ///
    struct InventorySlot {
        std::unique_ptr<nork::Item> item;

        InventorySlot(std::unique_ptr<nork::Item> item);

        static InventorySlot blank();
    };

  public:
    Inventory(SLOTIDX_T nslots);

    ///
    /// Removes an item from an inventory slot
    /// returns wether an item was removed or not
    ///
    bool removeItem(SLOTIDX_T slot);
};
} // namespace nork

#endif // !NORK_INVENTORY_H
