set(source_files
    model/access-controller.cc
    model/authenticator.cc
    model/encryptor.cc
    model/geofence-manager.cc
    model/identity-revoker.cc
    model/logger.cc
    model/trust-manager.cc
)

set(header_files
    model/access-controller.h
    model/authenticator.h
    model/encryptor.h
    model/geofence-manager.h
    model/identity-revoker.h
    model/logger.h
    model/trust-manager.h
)

build_lib(
  LIBNAME zero-trust
  SOURCE_FILES ${source_files}
  HEADER_FILES ${header_files}
  LIBRARIES_TO_LINK ${libcore} ${libnetwork} ${libinternet} ${libwifi}
)

