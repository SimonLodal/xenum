/**
 * @file
 * @author Simon Lodal
 * @copyright 2018 Simon Lodal <simonl@parknet.dk>
 * @license GNU GPL version 3
 */
#ifndef TEST_XENUM_XENUMS_ICMP_HPP
#define TEST_XENUM_XENUMS_ICMP_HPP

#include <cstdint>
#include <xenum3/Xenum.hpp>

namespace test {
namespace xenum {
namespace xenums {


/**
 * IP ICMP types enum, for testing custom properties.
 */

#define XENUM_DECL_IcmpTypes (test::xenum::xenums::, IcmpTypes, IcmpType, uint8_t, , (		\
	(Ipv4, bool, false),									\
	(Ipv6, bool, false),									\
	(NfName, cstring, , 1)									\
	))

// FIXME:
// - Is the IPv6 Redirect message semantically the same as in IPv4? Or is it only something NDP related?
// - Figure out missing iptables names.
#define XENUM_VALS_IcmpTypes(V,C)	\
	V(C, EchoReply,				true,	true,	("echo-reply", "pong"))		\
	V(C, PacketTooBig,			false,	true)					\
	V(C, DestinationUnreachable,		true,	true,	("destination-unreachable"))	\
	V(C, SourceQuench,			true,	false,	("source-quench"))		\
	V(C, Redirect,				true,	true,	("redirect"))			\
	V(C, EchoRequest,			true,	true,	("echo-request", "ping"))	\
	V(C, RouterAdvertisement,		true,	true,	("router-advertisement"))	\
	V(C, RouterSolicitation,		true,	true,	("router-solicitation"))	\
	V(C, TimeExceeded,			true,	true,	("time-exceeded"))		\
	V(C, ParameterProblem,			true,	true,	("parameter-problem"))		\
	V(C, TimestampRequest,			true,	false,	("timestamp-request"))		\
	V(C, TimestampReply,			true,	false,	("timestamp-reply"))		\
	V(C, AddressMaskRequest,		true,	false,	("address-mask-request"))	\
	V(C, AddressMaskReply,			true,	false,	("address-mask-reply"))		\
	V(C, MulticastListenerQuery,		false,	true)					\
	V(C, MulticastListenerReport,		false,	true)					\
	V(C, MulticastListenerDone,		false,	true)					\
	V(C, NeighborSolicitation,		false,	true)					\
	V(C, NeighborAdvertisement,		false,	true)					\
	V(C, RouterRenumbering,			false,	true)					\
	V(C, NodeInformationQuery,		false,	true)					\
	V(C, NodeInformationResponse,		false,	true)					\
	V(C, InverseNDSolicitation,		false,	true)					\
	V(C, InverseNDAdvertisement,		false,	true)					\
	V(C, MLDv2Report,			false,	true)					\
	V(C, HomeAgentDiscoveryRequest,		false,	true)					\
	V(C, HomeAgentDiscoveryReply,		false,	true)					\
	V(C, MobilePrefixSolicitation,		false,	true)					\
	V(C, MobilePrefixAdvertisement,		false,	true)					\
	V(C, CertificationPathSolicitation,	false,	true)					\
	V(C, CertificationPathAdvertisement,	false,	true)					\
	V(C, MulticastRouterAdvertisement,	false,	true)					\
	V(C, MulticastRouterSolicitation,	false,	true)					\
	V(C, MulticastRouterTermination,	false,	true)					\
	V(C, RplControl,			false,	true)
XENUM3_DECLARE(IcmpTypes)


/**
 * IP ICMP codes enum, for testing custom properties.
 */
#define XENUM_DECL_IcmpCodes (test::xenum::xenums::, IcmpCodes, IcmpCode, uint8_t, , (		\
	(Ipv4, bool, false),									\
	(Ipv6, bool, false),									\
	(IcmpType, test::xenum::xenums::IcmpType),						\
	(NfName, cstring)									\
	))
// FIXME: iptables seems to miss some codes:
// - DestinationUNreachable.SourceHostIsolated.
// - ParameterProblem.BadLength
// - Figure out missing iptables names.
#define XENUM_VALS_IcmpCodes(V,C)	\
	V(C, NetworkUnreachable,		true,	true,	IcmpTypes::DestinationUnreachable,	"network-unreachable") \
	V(C, HostUnreachable,			true,	true,	IcmpTypes::DestinationUnreachable,	"host-unreachable") \
	V(C, ProtocolUnreachable,		true,	,	IcmpTypes::DestinationUnreachable,	"protocol-unreachable") \
	V(C, PortUnreachable,			true,	true,	IcmpTypes::DestinationUnreachable,	"port-unreachable") \
	V(C, FragmentationRequired,		true,	,	IcmpTypes::DestinationUnreachable,	"fragmentation-needed") \
	V(C, SourceRouteFailed,			true,	,	IcmpTypes::DestinationUnreachable,	"source-route-failed") \
	V(C, NetworkUnknown,			true,	,	IcmpTypes::DestinationUnreachable,	"network-unknown") \
	V(C, HostUnknown,			true,	,	IcmpTypes::DestinationUnreachable,	"host-unknown") \
	V(C, NetworkProhibited,			true,	,	IcmpTypes::DestinationUnreachable,	"network-prohibited") \
	V(C, HostProhibited,			true,	,	IcmpTypes::DestinationUnreachable,	"host-prohibited") \
	V(C, TosNetworkUnreachable,		true,	,	IcmpTypes::DestinationUnreachable,	"TOS-network-unreachable") \
	V(C, TosHostUnreachable,		true,	,	IcmpTypes::DestinationUnreachable,	"TOS-host-unreachable") \
	V(C, CommunicationProhibited,		true,	true,	IcmpTypes::DestinationUnreachable,	"communication-prohibited") \
	V(C, HostPrecedenceViolation,		true,	,	IcmpTypes::DestinationUnreachable,	"host-precedence-violation") \
	V(C, PrecedenceCutoff,			true,	,	IcmpTypes::DestinationUnreachable,	"precedence-cutoff") \
	V(C, NetworkRedirect,			true,	,	IcmpTypes::Redirect,			"network-redirect") \
	V(C, HostRedirect,			true,	,	IcmpTypes::Redirect,			"host-redirect") \
	V(C, TosNetworkRedirect,		true,	,	IcmpTypes::Redirect,			"TOS-network-redirect") \
	V(C, TosHostRedirect,			true,	,	IcmpTypes::Redirect,			"TOS-host-redirect") \
	V(C, TtlZeroInTransmit,			true,	true,	IcmpTypes::TimeExceeded,		"ttl-zero-during-transit") \
	V(C, TtlZeroInReassembly,		true,	true,	IcmpTypes::TimeExceeded,		"ttl-zero-during-reassembly") \
	V(C, IpHeaderBad,			true,	true,	IcmpTypes::ParameterProblem,		"ip-header-bad") \
	V(C, MissingOption,			true,	false,	IcmpTypes::ParameterProblem,		"required-option-missing") \
	V(C, BadLength,				true,	false,	IcmpTypes::ParameterProblem,		"") \
	V(C, UnknownNextHeader,			false,	true,	IcmpTypes::ParameterProblem,		"") \
	V(C, UnknownIpv6Option,			false,	true,	IcmpTypes::ParameterProblem,		"") \
	V(C, RouterRenumberingCommand,		false,	true,	IcmpTypes::RouterRenumbering,		"") \
	V(C, RouterRenumberingResult,		false,	true,	IcmpTypes::RouterRenumbering,		"") \
	V(C, RouterRenumberingReset,		false,	true,	IcmpTypes::RouterRenumbering,		"") \
	V(C, QueryIpv6Address,			false,	true,	IcmpTypes::NodeInformationQuery,	"") \
	V(C, QueryName,				false,	true,	IcmpTypes::NodeInformationQuery,	"") \
	V(C, QueryIpv4Address,			false,	true,	IcmpTypes::NodeInformationQuery,	"") \
	V(C, QuerySuccess,			false,	true,	IcmpTypes::NodeInformationResponse,	"") \
	V(C, QueryRefused,			false,	true,	IcmpTypes::NodeInformationResponse,	"") \
	V(C, QueryUnknown,			false,	true,	IcmpTypes::NodeInformationResponse,	"") \

XENUM3_DECLARE(IcmpCodes)

/* IPv6 codes:
- DestinationUnreachable
  x 0 no route to destination = network-unreachable
  x 1 communication with destination administratively prohibited = communication-prohibited
  - 2 beyond scope of source address
  x 3 address unreachable = host-unreachable
  x 4 port unreachable = port-unreachable
  - 5 source address failed ingress/egress policy
  - 6 reject route to destination
  - 7 Error in Source Routing Header
- TimeExceeded:
  x 0 hop limit exceeded in transit = TTL expired in transit
  x 1 fragment reassembly time exceeded = same
- ParameterProblem:
  x 0 erroneous header field encountered = ip-header-bad
  # 1 unrecognized Next Header type encountered
  # 2 unrecognized IPv6 option encountered
*/


} // namespace xenums
} // namespace xenum
} // namespace test
#endif // TEST_XENUM_XENUMS_ICMP_HPP
