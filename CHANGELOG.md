# Changelog

## [Unreleased]
### Added
- util/xenum4-inject util script for inspecting the generated code.

### Removed
- Util scripts xenum-inspect and xenum-postprocess replaced by xenum4-inject.


## [4.0] - 2018-04-18
### Changed
- Reorg API so container class contains enum-value objects instead of native enum values.
- Generate implementation of plain custom properties in source rather than header, like cstring.
- Many little API changes, like adding underscore prefix to container class functions,
  to minimize risk of name clash with enum values.
- Support clang.

## [3.1] - 2018-03-26
### Added
- Allow custom properties of string type.

## [3.0] - 2018-03-18
### Added
- Initial working release.
