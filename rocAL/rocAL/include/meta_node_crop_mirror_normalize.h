/*
Copyright (c) 2019 - 2020 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once
#include <set>
#include <memory>
#include "bounding_box_graph.h"
#include "meta_data.h"
#include "node.h"
#include "node_crop_mirror_normalize.h"
#include "parameter_vx.h"
class CropMirrorNormalizeMetaNode:public MetaNode
{
    public:
        CropMirrorNormalizeMetaNode() {};
        void update_parameters(MetaDataBatch* input_meta_data)override;
        std::shared_ptr<CropMirrorNormalizeNode> _node = nullptr;
    private:
        void initialize();
        std::shared_ptr<RaliCropParam> _meta_crop_param;
        vx_array _dstImgWidth, _dstImgHeight, _x1, _y1, _mirror, _src_width, _src_height;
        std::vector<uint> _width_val, _height_val, _x1_val, _y1_val, _mirror_val,_src_width_val,_src_height_val;
};
