idf_component_register(SRCS "app.c"
                    INCLUDE_DIRS "include"
                    REQUIRES ulp driver)

set(ulp_app_name ulp_${COMPONENT_NAME})
set(ulp_sources "ulp/ulp_app.c")
set(ulp_exp_dep_srcs "app.c")

ulp_embed_binary(${ulp_app_name} "${ulp_sources}" "${ulp_exp_dep_srcs}")
