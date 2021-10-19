/**
 * Copyright (c) 2021 Yuriy Lisovskiy
 */

#pragma once

// STL
#include <string>

// xalwart
#include <xalwart.base/datetime.h>
#include <xalwart.orm/db/migration.h>


class Migration001 : public xw::orm::db::Migration
{
public:
	inline explicit Migration001(auto* backend)
		: xw::orm::db::Migration(backend, "001_initial", true)
	{
		this->create_table(
			"oauth_client",
			[](auto& table)
			{
				table.template column<std::string>(
					"client_id", {.primary_key=true, .max_len=255, .unique=true, .null=false}
				);
				table.template column<std::string>("client_secret", {.max_len=64, .null=false});
				table.template column<xw::dt::Datetime>("created_at", {.null=false});
				table.template column<xw::dt::Datetime>("updated_at", {.null=false});
			}
		);
	}
};
