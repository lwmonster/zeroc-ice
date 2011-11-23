// **********************************************************************
//
// Copyright (c) 2003-2010 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

import Demo.*;

class CallbackReceiverI extends _CallbackReceiverDisp
{
    CallbackReceiverI()
    {
    }

    public void
    callback(int num, Ice.Current current)
    {
        System.out.println("received callback #" + num);
    }
}