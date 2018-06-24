// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2017 The SKUCOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    BOOST_CHECK(Checkpoints::CheckBlock(0, p0));
    BOOST_CHECK(Checkpoints::CheckBlock(623933, p623933));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(0, p623933));
    BOOST_CHECK(!Checkpoints::CheckBlock(623933, p0));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(0+1, p623933));
    BOOST_CHECK(Checkpoints::CheckBlock(623933+1, p0));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 623933);
}

BOOST_AUTO_TEST_SUITE_END()
