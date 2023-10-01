

include(${SRC_TOP_DIR}/${MOUNTED_COMMON}/model/common_model/common_model.cmake)

SET(NRF_MODEL_DIR ${SRC_TOP_DIR}/${MOUNTED_COMMON}/model/nrf)

include_directories(${NRF_MODEL_DIR})

file(GLOB NRF_MODEL_SRC_FILES
