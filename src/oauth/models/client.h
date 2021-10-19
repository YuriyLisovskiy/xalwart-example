/*
 * Copyright (c) 2021 Yuriy Lisovskiy
 */

#pragma once

// STL
#include <string>

// xalwart
#include <xalwart.base/datetime.h>
#include <xalwart.base/abc/base.h>
#include <xalwart.orm/db/model.h>


class ClientModel : public xw::orm::db::Model, public xw::abc::IJsonSerializable
{
public:
	std::string client_id;
	std::string client_secret;
	xw::dt::Datetime created_at;
	xw::dt::Datetime updated_at;

	static constexpr const char* meta_table_name = "oauth_client";
	static constexpr bool meta_omit_pk = false;

	inline static const std::tuple meta_columns = {
		xw::orm::db::make_pk_column_meta("client_id", &ClientModel::client_id),
		xw::orm::db::make_column_meta("client_secret", &ClientModel::client_secret),
		xw::orm::db::make_column_meta("created_at", &ClientModel::created_at),
		xw::orm::db::make_column_meta("updated_at", &ClientModel::updated_at)
	};

	ClientModel() = default;

	ClientModel(
		std::string id, std::string secret,
		const xw::dt::Datetime& created_at, const xw::dt::Datetime& updated_at
	) :
		client_id(std::move(id)), client_secret(std::move(secret)),
		created_at(created_at), updated_at(updated_at)
	{
	}

	inline void __set_attr__(const char* attr_name, const void* data) override
	{
		this->set_attribute_to(ClientModel::meta_columns, attr_name, data);
	}

	[[nodiscard]]
	inline std::shared_ptr<const xw::obj::Object> __get_attr__(const char* attr_name) const override
	{
		return this->get_attribute_from(ClientModel::meta_columns, attr_name);
	}

	[[nodiscard]]
	inline std::string __str__() const override
	{
		if (this->is_null())
		{
			return "null";
		}

		return "Client:\n  id: " + this->client_id +
			"\n  secret: " + this->client_secret +
			"\n  created at: " + this->created_at.str() +
			"\n  updated at: " + this->updated_at.str();
	}

	[[nodiscard]]
	nlohmann::json to_json() const override
	{
		return {
			{"client_id", this->client_id},
			{"client_secret", this->client_secret},
			{"created_at", this->created_at.str()},
			{"updated_at", this->updated_at.str()}
		};
	}
};
