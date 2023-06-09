#!/pxrpythonsubst
#
# Copyright 2017 Pixar
#
# Licensed under the Apache License, Version 2.0 (the "Apache License")
# with the following modification; you may not use this file except in
# compliance with the Apache License and the following modification to it:
# Section 6. Trademarks. is deleted and replaced with:
#
# 6. Trademarks. This License does not grant permission to use the trade
#    names, trademarks, service marks, or product names of the Licensor
#    and its affiliates, except as required to comply with Section 4(c) of
#    the License and to reproduce the content of the NOTICE file.
#
# You may obtain a copy of the Apache License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the Apache License with the above modification is
# distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the Apache License for the specific
# language governing permissions and limitations under the Apache License.

from pxr import Gf, Usd, UsdSkel
import unittest


class TestUsdSkelBakeSkinning(unittest.TestCase):

    def test_DQSkinning(self):
        testFile = "dqs.usda"
        stage = Usd.Stage.Open(testFile)

        self.assertTrue(UsdSkel.BakeSkinning(stage.Traverse()))

        stage.GetRootLayer().Export("dqs.baked.usda")


    def test_DQSkinningWithInterval(self):
        testFile = "dqs.usda"
        stage = Usd.Stage.Open(testFile)

        self.assertTrue(UsdSkel.BakeSkinning(
            stage.Traverse(), Gf.Interval(1, 10)))

        stage.GetRootLayer().Export("dqs.bakedInterval.usda")


    def test_LinearBlendSkinning(self):
        testFile = "lbs.usda"
        stage = Usd.Stage.Open(testFile)

        self.assertTrue(UsdSkel.BakeSkinning(stage.Traverse()))

        stage.GetRootLayer().Export("lbs.baked.usda")


    def test_LinearBlendSkinningWithInterval(self):
        testFile = "lbs.usda"
        stage = Usd.Stage.Open(testFile)

        self.assertTrue(UsdSkel.BakeSkinning(
            stage.Traverse(), Gf.Interval(1, 10)))

        stage.GetRootLayer().Export("lbs.bakedInterval.usda")


    def test_BlendShapes(self):
        testFile = "blendshapes.usda"
        stage = Usd.Stage.Open(testFile)

        self.assertTrue(UsdSkel.BakeSkinning(stage.Traverse()))
        
        stage.GetRootLayer().Export("blendshapes.baked.usda")


    def test_BlendShapesWithNormals(self):
        testFile = "blendshapesWithNormals.usda"
        stage = Usd.Stage.Open(testFile)

        self.assertTrue(UsdSkel.BakeSkinning(stage.Traverse()))
        
        stage.GetRootLayer().Export("blendshapesWithNormals.baked.usda")


if __name__ == "__main__":
    unittest.main()
