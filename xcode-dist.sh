## (Optional) Set Xcode as default build tool
#sudo xcode-select -s /Applications/Xcode.app
#
## (Optional) Save app-specific password to keychain
# xcrun altool \
#      --store-password-in-keychain-item ${KEYCHAIN} \
#      -u ${USERNAME} \
#      -p <PASSWORD>
#
## (Optional) Double-check if multiple providers are available
#xcrun altool \
#      --list-providers \
#      -u ${USERNAME} \
#      -p ${PASSWORD}
#
#
# Clean up app bundle
xattr -cr ${BUNDLE_PATH}"lilDevil.app/"

# Code sign bundle (enable hardened runtime)
codesign -s ${PROVIDER} -v ${BUNDLE_PATH}"lilDevil.app/" -o runtime --force
codesign -s ${PROVIDER} -v ${BUNDLE_PATH}"lilDevil.app/Contents/MacOS/lilDevil" -o runtime --force

# ZIP bundle
rm -f ${BUNDLE_PATH}"lilDevil.zip"
zip -r ${BUNDLE_PATH}"lilDevil.zip" ${BUNDLE_PATH}"lilDevil.app"

# Request app notarization
NOTARIZATION=$(xcrun altool \
      --notarize-app \
      --primary-bundle-id ${BUNDLE_ID} \
      --asc-provider ${PROVIDER} \
      -u ${USERNAME} \
      -p ${PASSWORD} \
      -f ${BUNDLE_PATH}"lilDevil.zip" | grep "RequestUUID = " | sed "s/RequestUUID = //")

# Check on status
sleep 90
xcrun altool \
      --notarization-info ${NOTARIZATION} \
      -u ${USERNAME} \
      --asc-provider ${PROVIDER} \
      -p ${PASSWORD}

# Staple the Ticket to Distro
xcrun stapler \
      staple ${BUNDLE_PATH}"lilDevil.app"

## Uploads the given app archive to the App Store (experimental)
#xcrun altool \
#      --validate-app \
#      --asc-provider ${PROVIDER} \
#      -t "osx" \
#      -u ${USERNAME} \
#      -p ${PASSWORD} \
#      -f ${BUNDLE_PATH}"lilDevil.zip"
#
#xcrun altool \
#      --upload-app \
#      --asc-provider ${PROVIDER} \
#      -t "osx" \
#      -u ${USERNAME} \
#      -p ${PASSWORD} \
#      -f ${BUNDLE_PATH}"lilDevil.zip"

# Cleanup
rm -f ${BUNDLE_PATH}"lilDevil.zip"
