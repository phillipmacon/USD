set(PXR_PREFIX pxr/usd)
set(PXR_PACKAGE usd)


pxr_cpp_bin(usdtree
        LIBRARIES
        ar
        sdf
        tf
        usd
        usdUtils
        )

pxr_install_test_dir(
    SRC testenv/testUsdTree
    DEST testUsdTree
)

pxr_register_test(testUsdTree
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --flatten input.usda"
    STDOUT_REDIRECT output.txt
    DIFF_COMPARE output.txt
    EXPECTED_RETURN_CODE 0
)

pxr_install_test_dir(
    SRC testenv/testUsdTreePayload
    DEST testUsdTreeLoaded
)

pxr_register_test(testUsdTreeLoaded
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --flatten input.usda"
    STDOUT_REDIRECT output.txt
    DIFF_COMPARE output.txt
    EXPECTED_RETURN_CODE 0
)

pxr_install_test_dir(
    SRC testenv/testUsdTreePayload
    DEST testUsdTreeUnloaded
)

pxr_register_test(testUsdTreeUnloaded
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --flatten --unloaded input.usda"
    STDOUT_REDIRECT output_unloaded.txt
    DIFF_COMPARE output_unloaded.txt
    EXPECTED_RETURN_CODE 0
)


pxr_install_test_dir(
    SRC testenv/testUsdTree
    DEST testUsdTreeAttributes
)

pxr_register_test(testUsdTreeAttributes
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --flatten --attributes --metadata input.usda"
    STDOUT_REDIRECT output_attributes.txt
    DIFF_COMPARE output_attributes.txt
    EXPECTED_RETURN_CODE 0
)


pxr_install_test_dir(
    SRC testenv/testUsdTreePayload
    DEST testUsdTreeNotFlattened
)

pxr_register_test(testUsdTreeNotFlattened
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --unloaded --attributes --metadata input.usda"
    STDOUT_REDIRECT output_notflattened.txt
    DIFF_COMPARE output_notflattened.txt
    EXPECTED_RETURN_CODE 0
)


pxr_install_test_dir(
    SRC testenv/testUsdTreePayload
    DEST testUsdTreeMasked
)

pxr_register_test(testUsdTreeMasked
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --flatten --attributes --metadata --mask /root/child1 input.usda"
    STDOUT_REDIRECT output_masked.txt
    DIFF_COMPARE output_masked.txt
    EXPECTED_RETURN_CODE 0
)


pxr_install_test_dir(
    SRC testenv/testUsdTreePayload
    DEST testUsdTreeFlattenLayerStack
)

pxr_register_test(testUsdTreeFlattenLayerStack
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --flattenLayerStack input.usda"
    STDOUT_REDIRECT output_fls.txt
    DIFF_COMPARE output_fls.txt
    EXPECTED_RETURN_CODE 0
)


pxr_install_test_dir(
    SRC testenv/testUsdTreePayload
    DEST testUsdTreeSimple
)

pxr_register_test(testUsdTreeSimple
    COMMAND "${CMAKE_INSTALL_PREFIX}/bin/usdtree --simple input.usda"
    STDOUT_REDIRECT output_simple.txt
    DIFF_COMPARE output_simple.txt
    EXPECTED_RETURN_CODE 0
)
