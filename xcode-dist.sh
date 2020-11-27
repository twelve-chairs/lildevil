APP_NAME="lilDevil"
USERNAME="asimakov@twelvechairs-software.com"

KEYCHAIN="XcodeSecurity"
PASSWORD="@keychain:"${KEYCHAIN}

BUNDLE_ID="com.twelvechairs-software."${APP_NAME}
BUNDLE_PATH="/Users/vokamisair/Documents/dev/"${APP_NAME}"/dist/homebrew/"

DEVELOPER_ID="Developer ID Application: Twelve Chairs Software, LLC"
DEVELOPER_APPLICATION="3rd Party Mac Developer Application: Twelve Chairs Software, LLC"
DEVELOPER_INSTALLER="3rd Party Mac Developer Installer: Twelve Chairs Software, LLC"

## (Optional) Set Xcode as default build tool
#sudo xcode-select -s /Applications/Xcode.app
#
## (Optional) Save app-specific password to local keychain
# xcrun altool \
#      --store-password-in-keychain-item ${KEYCHAIN} \
#      -u ${USERNAME} \
#      -p <PASSWORD>
#
#
# Clean up app bundle
xattr -cr ${BUNDLE_PATH}${APP_NAME}".app/"

# Code sign bundle (enable hardened runtime)
codesign \
      -dvv ${BUNDLE_PATH}${APP_NAME}".app/" \
      --sign ${DEVELOPER_ID} \
      --options runtime \
      --timestamp \
      --force

codesign \
      -dvv ${BUNDLE_PATH}${APP_NAME}".app/Contents/MacOS/"${APP_NAME} \
      --sign ${DEVELOPER_ID} \
      --options runtime \
      --timestamp \
      --force

spctl -vvv --assess --type exec ${BUNDLE_PATH}${APP_NAME}".app"

# Request app notarization
pushd ${BUNDLE_PATH}
  rm -f ${APP_NAME}".zip"
  zip -r ${APP_NAME}".zip" ${APP_NAME}".app"
popd

NOTARIZATION_ID=$(xcrun altool \
      --notarize-app \
      --primary-bundle-id ${BUNDLE_ID} \
      -u ${USERNAME} \
      -p ${PASSWORD} \
      -f ${BUNDLE_PATH}${APP_NAME}".zip" | grep "RequestUUID = " | sed "s/RequestUUID = //")

rm -rf ${BUNDLE_PATH}${APP_NAME}".zip"

echo "Waiting for notarization results..."
sleep 360

# Check on status
xcrun altool \
      --notarization-info ${NOTARIZATION_ID} \
      -u ${USERNAME} \
      -p ${PASSWORD}

# Staple the Ticket to Distro
xcrun stapler \
      staple ${BUNDLE_PATH}${APP_NAME}".app"

codesign \
      -dvv ${BUNDLE_PATH}${APP_NAME}".app/" \
      --entitlements "entitlements" \
      --sign ${DEVELOPER_APPLICATION} \
      --options runtime \
      --timestamp \
      --force

codesign \
      -dvv ${BUNDLE_PATH}${APP_NAME}".app/Contents/MacOS/"${APP_NAME} \
      --entitlements "entitlements" \
      --sign ${DEVELOPER_APPLICATION} \
      --options runtime \
      --timestamp \
      --force

codesign \
      --verify ${BUNDLE_PATH}${APP_NAME}".app/"

productbuild \
      --component ${BUNDLE_PATH}${APP_NAME}".app" /Applications ${BUNDLE_PATH}${APP_NAME}".pkg" \
      --sign ${DEVELOPER_INSTALLER}

# Validate app archive for the App Store
xcrun altool \
      --validate-app \
      -t "osx" \
      -u ${USERNAME} \
      -p ${PASSWORD} \
      -f ${BUNDLE_PATH}${APP_NAME}".pkg"

#xcrun altool \
#      --upload-app \
#      -t "osx" \
#      -u ${USERNAME} \
#      -p ${PASSWORD} \
#      -f ${BUNDLE_PATH}"lilDevil.pkg"
#
#
## Cleanup
#rm -rf ${BUNDLE_PATH}"lilDevil.app"
